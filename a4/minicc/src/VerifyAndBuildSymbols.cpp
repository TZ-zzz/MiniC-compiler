//
// Created by Fan Long on 2020/12/4.
//

//Add necessary headers you want
#include "VerifyAndBuildSymbols.h"
#include "Declarations.h"
#include "Terms.h"
#include "Types.h"
#include "Exprs.h"
#include "Statements.h"
#include "Program.h"
#include <string>
#include <sstream>

namespace minicc {

    void VerifyAndBuildSymbols::visitASTNode(ASTNode *node) {
        //start your code here
        //Hint: set root of the node before visiting children
        node->setRoot(VisitingProgram);
        ASTVisitor::visitASTNode(node);
    }

    void VerifyAndBuildSymbols::visitProgram(Program *prog) {
        //start your code here
        VisitingProgram = prog;
        ASTVisitor::visitProgram(prog);
        if (prog->syslibFlag()) {
            // Manually populate the function symbol table
            // ...
            prog->funcTable()->insert_funcsym("getint", Type(Type::Int), (std::vector<Type>) {}, true);
            prog->funcTable()->insert_funcsym("putint", Type(Type::Void), (std::vector<Type>) {Type(Type::Int)}, true);
            prog->funcTable()->insert_funcsym("putnewline", Type(Type::Void), std::vector<Type>(), true);
        }
    }

    void VerifyAndBuildSymbols::visitVarDecl(VarDeclaration *decl) {
        //start your code here
        ASTVisitor::visitVarDecl(decl);
        ASTNode* current_scope = decl->getParentScope();
        for (size_t i = 0; i < decl->numVarReferences(); i++){
            VarReference *var_ref = decl->varReference(i);
            std::string var_name = var_ref->identifier()->name();
            //Hint: Check that same variable cannot be declared twice in the same scope
            if (current_scope->scopeVarTable()->contains_var(var_name)){
                Errors.push_back(ErrorMessage("Redefinition of variable/parameter \"" + var_name + "\" in the same scope!", var_ref->srcLoc()));
            }
            else{
                Type t = Type(decl->declType());
                // if it is an array, set the size of the array
                if (var_ref->isArray()){
                    t.setIsArray(((IntLiteralExpr *) var_ref->indexExpr())->value());
                }
                current_scope->scopeVarTable()->insert_varsym(var_name, t);
            }
        }

    }

    void VerifyAndBuildSymbols::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
        std::vector<Type> param_types;
        std::vector<std::string> param_names;
        for (size_t i = 0; i < func->numParameters(); i++){
            param_types.push_back(Type(func->parameter(i)->type()));
            param_names.push_back(func->parameter(i)->name());
        }
        FuncSymbolTable *func_table = this->VisitingProgram->funcTable();
        if (func_table->contains_func(func->name())){
            FuncSymbolEntry * f_entry = func_table->get_funcsym(func->name());
            //Hint: Check return type of the function does not match with each other
            if (f_entry->ReturnType != Type(func->returnType())){
                Errors.push_back(ErrorMessage("Definition of function \"" + func->name() + "()\" with different return type!", func->srcLoc()));
            }
            //      Check number of parameters should match with each other
            if (f_entry->ParameterTypes.size() != param_types.size()){
                Errors.push_back(ErrorMessage("Definition of function \"" + func->name() + "()\" with different number of parameters!", func->srcLoc()));
            }
            //      Check each parameter type should match with each other
            for (size_t i = 0; i < param_types.size(); i++){
                if (f_entry->ParameterTypes[i] != param_types[i]){
                    Errors.push_back(ErrorMessage("Definition of function \"" + func->name() + "()\" with different parameter type at position " + std::to_string(i) + "!", func->srcLoc()));
                }
            }
            //      Check there should be only one definition of the function
            if (f_entry->HasBody && func->hasBody()){
                Errors.push_back(ErrorMessage("Redefinition of function \"" + func->name() + "()\"!", func->srcLoc()));
            }
        }
        else {
            func_table->insert_funcsym(func->name(), Type(func->returnType()), param_types, true);
        }

        if (func->hasBody()){
            func_table->get_funcsym(func->name())->HasBody = true;
            for (size_t i = 0; i < param_types.size(); i++){
                //      Check parameters cannot have the same name
                if (func->body()->scopeVarTable()->contains_var(param_names[i])){
                    Errors.push_back(ErrorMessage("Redefinition of variable/parameter \"" + param_names[i] + "\" in the same scope!", func->parameter(i)->srcLoc()));
                }
                else{
                    func->body()->scopeVarTable()->insert_varsym(param_names[i], param_types[i]);
                }
            }
            Statement* last_stm = nullptr;
            if (func->body()->numChildren() > 0){
                last_stm = (Statement*) func->body()->getChild(func->body()->numChildren() - 1);
            }
            //      Check the last statement a function body must be return if the return type is not void
            if (!func->returnType().isVoid() && (last_stm == nullptr|| !last_stm->isReturn())){
                Errors.push_back(ErrorMessage("The function \"" + func->name() + "()\" need to return a value at its end!", func->srcLoc()));
            }

            
        }
        ASTVisitor::visitFuncDecl(func);

    }

    void VerifyAndBuildSymbols::visitIfStmt(IfStatement *stmt) {
        //start your code here
        ASTVisitor::visitIfStmt(stmt);

        Expr *cond = stmt->condExpr();
        //Hint: Check the conditional expression must have bool type
        if (!cond->exprType().isBool()){
            Errors.push_back(ErrorMessage("Conditional expression in if statement has non-bool type!", cond->srcLoc()));
        }

    }

    void VerifyAndBuildSymbols::visitForStmt(ForStatement *stmt) {
        //start your code here
        ASTVisitor::visitForStmt(stmt);
        Expr* sec_expr = stmt->condExpr();
        //Hint: Check the second expression in for must be either null or bool type
        if (sec_expr != nullptr && !sec_expr->exprType().isBool()){
            Errors.push_back(ErrorMessage("Conditional expression in for statement has non-bool type!", sec_expr->srcLoc()));
        }

    }

    void VerifyAndBuildSymbols::visitWhileStmt(WhileStatement *stmt) {
        //start your code here
        ASTVisitor::visitWhileStmt(stmt);
        Expr *cond = stmt->condExpr();
        //Hint: Check the conditional expression must have bool type
        if (!cond->exprType().isBool()){
            Errors.push_back(ErrorMessage("Conditional expression in while statement has non-bool type!", cond->srcLoc()));
        }

    }

    void VerifyAndBuildSymbols::visitReturnStmt(ReturnStatement *stmt) {
        //start your code here
        ASTVisitor::visitReturnStmt(stmt);
        FuncDeclaration *func = stmt->getParentFunction();
        if (!func->returnType().isVoid()){
            //      Check Non-Void function must have an expression to return
            if (!stmt->hasReturnExpr()){
                Errors.push_back(ErrorMessage("Function has non-void return type, but the return statement has no returned expression!", stmt->srcLoc()));
            }
            //      Check the return type and the returned expression type must match
            else if (stmt->hasReturnExpr() && stmt->returnExpr()->exprType() != func->returnType()){
                Errors.push_back(ErrorMessage("Function has return type \"" + func->returnType().toString() + "\", but the returned expression has type \"" + stmt->returnExpr()->exprType().toString() + "\"!", stmt->srcLoc()));
            }
        }
        else{
            //Hint: Check void function must have no expression to return
            if (stmt->hasReturnExpr()){
                Errors.push_back(ErrorMessage("Function has void return type, but the return statement has a returned expression!", stmt->srcLoc()));
            }
        }
    }

    void VerifyAndBuildSymbols::visitBreakStmt(BreakStatement *stmt) {
        //start your code here
        ASTVisitor::visitBreakStmt(stmt);
        //Hint: Check Break statement must appear inside a for statement
        if (!stmt->getParentForStatement()){
            Errors.push_back(ErrorMessage("Break statement must appear inside a for/while statement!", stmt->srcLoc()));
        }

    }

    void VerifyAndBuildSymbols::visitUnaryExpr(UnaryExpr *expr) {
        //start your code here
        ASTVisitor::visitUnaryExpr(expr);
        //Hint: Check Negate opcode must have int operand!
        if (expr->opcode() == Expr::Sub && !((Expr*)expr->getChild(0))->exprType().isInt()){
            Errors.push_back(ErrorMessage("Negate \"-\" opcode must have int operand!", expr->srcLoc()));
        }
        //      Check Not opcode must have bool operand
        else if (expr->opcode() == Expr::Not && !((Expr*)expr->getChild(0))->exprType().isBool()){
            Errors.push_back(ErrorMessage("Not \"!\" opcode must have bool operand!", expr->srcLoc()));
        }
        expr->setExprType(((Expr*)expr->getChild(0))->exprType());
    }

    void VerifyAndBuildSymbols::visitBinaryExpr(BinaryExpr *expr) {
        //start your code here
        ASTVisitor::visitBinaryExpr(expr);
        Expr *e_1 = (Expr*)expr->getChild(0);
        Expr *e_2 = (Expr*)expr->getChild(1);
        //Hint: Check that for logical opcode, both operand need to be bool
        if (expr->opcode() == Expr::And || expr->opcode() == Expr::Or){
            if (!e_1->exprType().isBool() || !e_2->exprType().isBool()){
                Errors.push_back(ErrorMessage("\"&&\"/\"||\" opcode must have bool operand!", expr->srcLoc()));
                expr->setExprType(Type(e_1->exprType()));
            }
            else{
                expr->setExprType(Type(Type::Bool));
            }

        }
        //      Check that for equal and not equal opcode, both operand need to be the same primitive types
        else if (expr->opcode() == Expr::Equal || expr->opcode() == Expr::NotEqual){
            if (e_1->exprType() != e_2->exprType() || e_1->exprType().arrayBound() || e_2->exprType().arrayBound()){
                Errors.push_back(ErrorMessage("\"==\"/\"!=\" opcode must have same primitive type operand!", expr->srcLoc()));
            }
            expr->setExprType(Type(Type::Bool));
        }
        else {
            //      Check that for arithmetic and other comparison operand, both operand need to be int
            if (!e_1->exprType().isInt() || !e_2->exprType().isInt()){
                Errors.push_back(ErrorMessage("\"" + Expr::opcodeToString(expr->opcode()) + "\" opcode must have int type operand!", expr->srcLoc()));
            }
            if (expr->opcode() == Expr::Less || expr->opcode() == Expr::LessEqual || expr->opcode() == Expr::Greater || expr->opcode() == Expr::GreaterEqual){
                expr->setExprType(Type(Type::Bool));
            }
            else{
                expr->setExprType(Type(Type::Int));
            }
        }

    }

    void VerifyAndBuildSymbols::visitCallExpr(CallExpr *expr) {
        //start your code here
        ASTVisitor::visitCallExpr(expr);
        std::string callee_name = expr->callee()->name();
        //Hint: Check Call undeclared function
        if (!expr->root()->funcTable()->contains_func(callee_name)){
            Errors.push_back(ErrorMessage("Function " + callee_name + "() is not declared before use!", expr->srcLoc()));
        }
        else{
            FuncSymbolEntry *callee = expr->root()->funcTable()->get_funcsym(callee_name);
            //      Check the number of arguments must match the number of parameters
            if (callee->ParameterTypes.size() != expr->numArgs()){
                Errors.push_back(ErrorMessage("Function " + callee_name + "() is declared with " + std::to_string(expr->numArgs()) + " parameters but called with " +std::to_string(callee->ParameterTypes.size()) + " arguments!", expr->srcLoc()));
            }
            else{
                for (int i = 0; i < expr->numArgs(); i++){
                    //      Check the type of each parameter must match the argument
                    if (expr->arg(i)->exprType() != callee->ParameterTypes[i]){
                        Errors.push_back(ErrorMessage("Function " + callee_name + "() does not match the type of the call argument at position " + std::to_string(i) + "!", expr->srcLoc()));
                    }
                }
            }
            expr->setExprType(callee->ReturnType);
        }
    }

    static Type verifyVarReference(std::vector<ErrorMessage> & Errors, Expr* expr, VarReference *ref) {
        //start your code here
        VarSymbolTable* table = expr->locateDeclaringTableForVar(ref->identifier()->name());
        //Hint: Check the vairable which is reference must be declared before
        if (!table){
            Errors.push_back(ErrorMessage("Variable " + ref->identifier()->name() + " is not declared before use!", expr->srcLoc()));
            return Type(Type::Void);
        }
        else{
            VarSymbolEntry* entry = table->get_varsym(ref->identifier()->name());
            if (ref->isArray()){
                //      Check index expression must have int type
                if (!ref->indexExpr()->exprType().isInt()){
                    Errors.push_back(ErrorMessage("Array index expressions must have int operand!", ref->indexExpr()->srcLoc()));
                }
                //      Check variable must be declared as an array for indexing
                if (!entry->VarType.arrayBound()){
                    Errors.push_back(ErrorMessage("Indexing an non-array variable!", expr->srcLoc()));
                }
                return entry->VarType.getIndexedType();
            }
            return entry->VarType;
        }
    }

    void VerifyAndBuildSymbols::visitVarExpr(VarExpr *expr) {
        //start your code here
        ASTVisitor::visitVarExpr(expr);
        //Hint: invoke verifyVarReference to verify
        expr->setExprType(verifyVarReference(Errors, expr, (VarReference*) expr->getChild(0)));
    }

    void VerifyAndBuildSymbols::visitAssignmentExpr(AssignmentExpr *expr) {
        //start your code here
        ASTVisitor::visitAssignmentExpr(expr);
        //Hint: invoke verifyVarReference to verify
        Type var_type = verifyVarReference(Errors, expr, (VarReference*) expr->getChild(0));
        //      Also, check var and assigned expression must have the same type
        if (var_type != ((Expr*) expr->getChild(1))->exprType()){
            Errors.push_back(ErrorMessage("Variable and the assignment expression do not have the same type!", expr->srcLoc()));
        }
        expr->setExprType(var_type);
    }

    void VerifyAndBuildSymbols::visitIntLiteralExpr(IntLiteralExpr *literal) {
        //start your code here
        //Hint: Check Integer literal must be inside the range of int
        if (literal->exprType().isVoid()){
            Errors.push_back(ErrorMessage("Integer literal must be inside the range of int!", literal->srcLoc()));
        }
        literal->setExprType(Type(Type::Int));
    }

    void VerifyAndBuildSymbols::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        //start your code here
        assert(literal->exprType().isBool());
    }

    //print collected error messages
    std::string VerifyAndBuildSymbols::genErrorMessages() {
        std::stringbuf buf;
        std::ostream os(&buf);

        for (size_t i = 0; i < Errors.size(); i++) {
            os << Errors[i].Msg << " (" << Errors[i].SrcLoc.Line << ":" << Errors[i].SrcLoc.Row << ")\n";
        }

        return buf.str();
    }

}