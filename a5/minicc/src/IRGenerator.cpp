//
// Created by Fan Long on 2020/12/6.
//

//add more header files if your want
#include "IRGenerator.h"
#include "llvm/IR/Module.h"
#include "Declarations.h"
#include "Program.h"
#include "Exprs.h"
#include "Statements.h"

namespace minicc {
    //add your member helper functions
    llvm::Type *IRGenerator::getLLVMType(Type::PrimitiveTypeEnum type) {
        switch (type) {
            case Type::Void:
                return llvm::Type::getVoidTy(*TheContext);
            case Type::Bool:
                return llvm::Type::getInt1Ty(*TheContext);
            case Type::Int:
                return llvm::Type::getInt32Ty(*TheContext);
        }
    }

    llvm::Value *IRGenerator::getLLVMValue(Expr* expr){
        auto it = expr_map.find(expr);
        assert(it != expr_map.end());
        if (it != expr_map.end()) {
            return it->second;
        }
        return nullptr;
    }

    void IRGenerator::visitProgram(Program *prog) {
        //Initlize llvm module and builder
        TheModule = std::make_unique<llvm::Module>(ModuleName, *TheContext);
        TheBuilder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
        //start your code here
        FuncSymbolTable *func_table = prog->funcTable();
        // Insert all of functions into TheModule
        for (auto it = func_table->begin(); it != func_table->end(); it++) {
            FuncSymbolEntry entry = it->second;
            std::vector<llvm::Type*> para_types;
            for (size_t i = 0; i < entry.ParameterTypes.size(); i++) {
                para_types.push_back(getLLVMType(entry.ParameterTypes[i].primitiveType()));
            }
            llvm::FunctionType *func_type = llvm::FunctionType::get(getLLVMType(entry.ReturnType.primitiveType()), para_types, false);
            llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, it->first, TheModule.get());
        }
        ASTVisitor::visitProgram(prog);
    }
    

    void IRGenerator::visitVarDecl(VarDeclaration *decl) {
        //start your code here
        llvm::Type *var_type = getLLVMType(decl->declType());
        for (size_t i = 0; i < decl->numVarReferences(); i++) {
            VarReference *var_ref = decl->varReference(i);
            VarSymbolTable *var_table = decl->locateDeclaringTableForVar(var_ref->identifier()->name());
            size_t array_size;
            if (var_ref->isArray()) {
                VarSymbolEntry entry = var_table->get(var_ref->identifier()->name());
                array_size = entry.VarType.arrayBound();
            } else {
                array_size = 0;
            }
            // Check the variables are global or local.
            if (decl->getParentScope()->isProgram()) {
                if (array_size == 0) {
                    llvm::GlobalVariable *global_var = new llvm::GlobalVariable(*TheModule, var_type, false, llvm::GlobalValue::CommonLinkage, llvm::ConstantInt::get(var_type, 0, true), var_ref->identifier()->name());
                    var_table->setLLVMValue(var_ref->identifier()->name(), global_var);
                } else {
                    llvm::ArrayType *array_type = llvm::ArrayType::get(var_type, array_size);
                    llvm::ConstantAggregateZero *const_array = llvm::ConstantAggregateZero::get(array_type);
                    llvm::GlobalVariable *global_var = new llvm::GlobalVariable(*TheModule, array_type, false, llvm::GlobalValue::CommonLinkage, const_array, var_ref->identifier()->name());
                    // set llvm::Value to variable table
                    var_table->setLLVMValue(var_ref->identifier()->name(), global_var);
                }
                
            }
            else {
                if (array_size == 0) {
                    llvm::AllocaInst *alloca_inst = TheBuilder->CreateAlloca(var_type, nullptr, var_ref->identifier()->name());
                    var_table->setLLVMValue(var_ref->identifier()->name(), alloca_inst);
                } else {
                    llvm::ArrayType *array_type = llvm::ArrayType::get(var_type, array_size);
                    llvm::AllocaInst *alloca_inst = TheBuilder->CreateAlloca(array_type, nullptr, var_ref->identifier()->name());
                    var_table->setLLVMValue(var_ref->identifier()->name(), alloca_inst);
                }
                
            }
        }

    }

    void IRGenerator::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
        llvm::Function *llvm_func = TheModule->getFunction(func->name());
        if (func->hasBody()){
            // create a entry basic block for function with body
            llvm::BasicBlock *entry_block = llvm::BasicBlock::Create(*TheContext, func->name(), llvm_func);
            TheBuilder->SetInsertPoint(entry_block);
            VarSymbolTable *var_table = func->body()->scopeVarTable();
            for (size_t i = 0; i < func->numParameters(); i++) {
                VarSymbolEntry entry = var_table->get(func->parameter(i)->name());
                llvm::Type *para_type = getLLVMType(entry.VarType.primitiveType());
                llvm::Value *para_value = TheBuilder->CreateAlloca(para_type, nullptr, func->parameter(i)->name());
                TheBuilder->CreateStore(llvm_func->getArg(i), para_value);
                var_table->setLLVMValue(func->parameter(i)->name(), para_value);
            }
        
            ASTVisitor::visitScope(func->body());
            // no return expr in void function. create one
            if (func->returnType().isVoid()) {
                if (!TheBuilder->GetInsertBlock()->getTerminator()) {
                    TheBuilder->CreateRetVoid();
                }
            }
        }


    }

    void IRGenerator::visitIfStmt(IfStatement *stmt) {
        //start your code here
        stmt->condExpr()->accept(this);
        llvm::Function *func = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock *then_block = llvm::BasicBlock::Create(*TheContext, "if.then_bb", func);
        llvm::BasicBlock *else_block = nullptr;
        llvm::BasicBlock *out_block = llvm::BasicBlock::Create(*TheContext, "if.out_bb", func);

        llvm::Value *cond = getLLVMValue(stmt->condExpr());
        // if there is a else statement, create a else block
        if (stmt->hasElse()) {
            else_block = llvm::BasicBlock::Create(*TheContext, "if.else", func);
            TheBuilder->CreateCondBr(cond, then_block, else_block);
        } else {
            TheBuilder->CreateCondBr(cond, then_block, out_block);
        }

        TheBuilder->SetInsertPoint(then_block);
        stmt->thenStmt()->accept(this);
        if (!TheBuilder->GetInsertBlock()->getTerminator()) {
            TheBuilder->CreateBr(out_block);
        }
        if (stmt->hasElse()) {
            TheBuilder->SetInsertPoint(else_block);
            stmt->elseStmt()->accept(this);
            if (!TheBuilder->GetInsertBlock()->getTerminator()) {
                TheBuilder->CreateBr(out_block);
            }
        }

        TheBuilder->SetInsertPoint(out_block);

    }

    void IRGenerator::visitForStmt(ForStatement *stmt) {
        //start your code here
        llvm::Function *func = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(*TheContext, "for.cond_bb", func);
        llvm::BasicBlock *body_block = llvm::BasicBlock::Create(*TheContext, "for.body_bb", func);
        llvm::BasicBlock *exit_block = llvm::BasicBlock::Create(*TheContext, "for.exit_bb", func);
        // store the nearest scope's exit block
        break_stmts.push_back(exit_block);
        if (stmt->initExpr()) {
            // first visit init expr
            stmt->initExpr()->accept(this);
        }
        TheBuilder->CreateBr(cond_block);

        TheBuilder->SetInsertPoint(cond_block);
        if (stmt->condExpr()) {
            // second visit cond expr
            stmt->condExpr()->accept(this);
            TheBuilder->CreateCondBr(getLLVMValue(stmt->condExpr()), body_block, exit_block);
        }
        else {
            TheBuilder->CreateBr(body_block);
        }
        
        TheBuilder->SetInsertPoint(body_block);
        // third visit body and iter expr
        stmt->body()->accept(this);
        llvm::BasicBlock *current_block = TheBuilder->GetInsertBlock();
        // check break or return 
        if (!current_block->getTerminator()) {
            if (stmt->iterExpr()) {
                stmt->iterExpr()->accept(this);
            }
            TheBuilder->CreateBr(cond_block);
        }
        TheBuilder->SetInsertPoint(exit_block);
        break_stmts.pop_back();
    }

    void IRGenerator::visitWhileStmt(WhileStatement *stmt) {
        //start your code here
        llvm::Function *func = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(*TheContext, "while_cond_bb", func);
        llvm::BasicBlock *body_block = llvm::BasicBlock::Create(*TheContext, "while_body_bb", func);
        llvm::BasicBlock *exit_block = llvm::BasicBlock::Create(*TheContext, "while_exit_bb", func);
        // store the nearest scope's exit block
        break_stmts.push_back(exit_block);
        if (!TheBuilder->GetInsertBlock()->getTerminator()){
            TheBuilder->CreateBr(cond_block);
        }
        TheBuilder->SetInsertPoint(cond_block);
        // first visit cond expr
        if (stmt->condExpr()) {
            stmt->condExpr()->accept(this);
            llvm::Value *cond = getLLVMValue(stmt->condExpr());
            TheBuilder->CreateCondBr(cond, body_block, exit_block);
        }
        else {
            TheBuilder->CreateBr(body_block);
        }

        TheBuilder->SetInsertPoint(body_block);
        // second visit body
        stmt->body()->accept(this);
        llvm::BasicBlock *current_block = TheBuilder->GetInsertBlock();
        // check break or return
        if (!current_block->getTerminator()) {
            TheBuilder->CreateBr(cond_block);
        }
        TheBuilder->SetInsertPoint(exit_block);
        break_stmts.pop_back();
    }

    void IRGenerator::visitReturnStmt(ReturnStatement *stmt) {
        //start your code here
        ASTVisitor::visitReturnStmt(stmt);
        if (stmt->hasReturnExpr()) {
            llvm::Value *value = TheBuilder->CreateRet(getLLVMValue(stmt->returnExpr()));
        } else {
            llvm::Value *value = TheBuilder->CreateRetVoid();
        }
    }

    void IRGenerator::visitBreakStmt(BreakStatement *stmt) {
        //start your code here
        // return the nearest scope's exit block
        TheBuilder->CreateBr(break_stmts.back());
    }


    void IRGenerator::visitUnaryExpr(UnaryExpr *expr) {
        //start your code here
        ASTVisitor::visitUnaryExpr(expr);
        llvm::Value *unary_value = getLLVMValue((Expr *) expr->getChild(0));
        llvm::Value *value;
        switch (expr->opcode()) {
            case UnaryExpr::ExprOpcode::Sub:
                value = TheBuilder->CreateNeg(unary_value);
                break;
            case UnaryExpr::ExprOpcode::Not:
                value = TheBuilder->CreateNot(unary_value);
                break;
        }
        expr_map.insert(std::make_pair(expr, value));
    }

    void IRGenerator::visitBinaryExpr(BinaryExpr *expr) {
        //start your code here
        if (expr->opcode() != Expr::ExprOpcode::And && expr->opcode() != Expr::ExprOpcode::Or){
            ASTVisitor::visitBinaryExpr(expr);
            llvm::Value *e1 = getLLVMValue((Expr *) expr->getChild(0));
            llvm::Value *e2 = getLLVMValue((Expr *) expr->getChild(1));
            switch(expr->opcode()){
                case Expr::ExprOpcode::Add:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateAdd(e1, e2)));
                    break;
                case Expr::ExprOpcode::Sub:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateSub(e1, e2)));
                    break;
                case Expr::ExprOpcode::Mul:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateMul(e1, e2)));
                    break;
                case Expr::ExprOpcode::Div:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateSDiv(e1, e2)));
                    break;
                case Expr::ExprOpcode::Equal:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateICmpEQ(e1, e2)));
                    break;
                case Expr::ExprOpcode::NotEqual:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateICmpNE(e1, e2)));
                    break;
                case Expr::ExprOpcode::Less:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateICmpSLT(e1, e2)));
                    break;
                case Expr::ExprOpcode::LessEqual:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateICmpSLE(e1, e2)));
                    break;
                case Expr::ExprOpcode::Greater:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateICmpSGT(e1, e2)));
                    break;
                case Expr::ExprOpcode::GreaterEqual:
                    expr_map.insert(std::make_pair(expr, TheBuilder->CreateICmpSGE(e1, e2)));
                    break;
            }
        }
        else{
            llvm::BasicBlock *current_block = TheBuilder->GetInsertBlock();
            llvm::BasicBlock *slow_block = llvm::BasicBlock::Create(*TheContext, "slow_block", current_block->getParent());
            llvm::BasicBlock *out_block = llvm::BasicBlock::Create(*TheContext, "out_block", current_block->getParent());
            // set cond branch
            expr->getChild(0)->accept(this);
            llvm::Value *e1 = getLLVMValue((Expr *) expr->getChild(0));
            if (expr->opcode() == Expr::ExprOpcode::And){
                TheBuilder->CreateCondBr(e1, slow_block, out_block);
            }
            else{
                TheBuilder->CreateCondBr(e1, out_block, slow_block);
            }
            TheBuilder->SetInsertPoint(slow_block);
            expr->getChild(1)->accept(this);
            llvm::Value *e2 = getLLVMValue((Expr *) expr->getChild(1));
            TheBuilder->CreateBr(out_block);
            TheBuilder->SetInsertPoint(out_block);
            // create phi node
            llvm::PHINode *phi = TheBuilder->CreatePHI(getLLVMType(Type::Bool), 2);
            if (expr->opcode() == Expr::ExprOpcode::And){
                phi->addIncoming(llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0, true), current_block);
                phi->addIncoming(e2, slow_block);
            }
            else{
                phi->addIncoming(llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 1, true), current_block);
                phi->addIncoming(e2, slow_block);
            }
            expr_map.insert(std::make_pair(expr, phi));
        }

    }

    void IRGenerator::visitCallExpr(CallExpr *expr) {
        //start your code here
        std::string func_name = expr->callee()->name();
        llvm::Function *func = TheModule->getFunction(func_name);
        std::vector<llvm::Value *> args;
        ASTVisitor::visitCallExpr(expr);
        for (int i = 0; i < expr->numArgs(); i++){
            args.push_back(getLLVMValue(expr->arg(i)));
        }
        llvm::Value *value = TheBuilder->CreateCall(func, args);
        expr_map.insert(std::make_pair(expr, value));
    }

    void IRGenerator::visitVarExpr(VarExpr *expr) {
        //start your code here
        ASTVisitor::visitVarExpr(expr);
        VarReference *var = (VarReference *) expr->getChild(0);
        std::string var_name = var->identifier()->name();
        VarSymbolTable *var_table = expr->locateDeclaringTableForVar(var_name);
        VarSymbolEntry var_entry = var_table->get(var_name);
        llvm::Type *var_type = getLLVMType(var_entry.VarType.primitiveType());
        if (var->isArray()){
            size_t bound = var_entry.VarType.arrayBound();
            llvm::ArrayType* array_type = llvm::ArrayType::get(getLLVMType(var_entry.VarType.primitiveType()), bound);
            llvm::Value *indices[2] = {TheBuilder->getInt32(0), getLLVMValue(var->indexExpr())};
            // the first param is the type of the array
            llvm::Value* value = TheBuilder->CreateGEP(array_type, var_entry.LLVMValue, indices);
            expr_map.insert(std::make_pair(expr, TheBuilder->CreateLoad(var_type, value)));
        }
        else {
            expr_map.insert(std::make_pair(expr, TheBuilder->CreateLoad(var_type, var_entry.LLVMValue)));
        }
    }

    void IRGenerator::visitAssignmentExpr(AssignmentExpr *expr) {
        //start your code here
        ASTVisitor::visitAssignmentExpr(expr);
        VarReference *var = (VarReference*) expr->getChild(0);
        std::string var_name = var->identifier()->name();
        VarSymbolTable *var_table = expr->locateDeclaringTableForVar(var_name);
        VarSymbolEntry var_entry = var_table->get(var_name);
        if (var->isArray()){
            size_t bound = var_entry.VarType.arrayBound();
            llvm::ArrayType* array_type = llvm::ArrayType::get(getLLVMType(var_entry.VarType.primitiveType()), bound);
            llvm::Value *indices[2] = {TheBuilder->getInt32(0), getLLVMValue(var->indexExpr())};
            llvm::Value* value = TheBuilder->CreateGEP(array_type, var_entry.LLVMValue, indices);
            TheBuilder->CreateStore(getLLVMValue((Expr *)expr->getChild(1)), value);
        }
        else {
            TheBuilder->CreateStore(getLLVMValue((Expr *)expr->getChild(1)), var_entry.LLVMValue);
        }
    }

    void IRGenerator::visitIntLiteralExpr(IntLiteralExpr *literal) {
        //start your code here
        ASTVisitor::visitIntLiteralExpr(literal);
        llvm::Constant *value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), literal->value(), true);
        expr_map.insert(std::make_pair(literal, value));
    }

    void IRGenerator::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        //start your code here
        llvm::Constant *value = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), literal->value(), true);
        expr_map.insert(std::make_pair(literal, value));
    }

    void IRGenerator::visitScope(ScopeStatement *stmt) {
        //start your code here
        for (size_t i = 0; i < stmt->numChildren(); i++){
            if (stmt->getChild(i)){
                stmt->getChild(i)->accept(this);
                if (TheBuilder->GetInsertBlock()->getTerminator()){
                    return;
                }
            }
        }
    }

}