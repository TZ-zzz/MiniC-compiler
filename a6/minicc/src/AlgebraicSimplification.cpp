//
// Created by Fan Long on 2020/12/9.
//

//add more header files if your want
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/PatternMatch.h"
#include "llvm/IR/BasicBlock.h"
#include <set>
#include <map>

using namespace llvm;

namespace {
    struct AlgebraicSimplification  : public FunctionPass {
        static char ID;
        AlgebraicSimplification() : FunctionPass(ID) {}

        virtual bool runOnFunction(Function &F) {
            errs() << "Working on function called " << F.getName() << "!\n";

            bool changed = false;
            while (changed){
                changed = false;
                for (BasicBlock &BB : F) {
                    for (Instruction &I : BB) {
                        if (Value *V = simplify(&I)) {
                            I.replaceAllUsesWith(V);
                            I.eraseFromParent();
                            changed = true;
                        }
                    }
                }
            }
            return changed;
            
        }

        Value *simplify(Value *v) {
            if (llvm::BinaryOperator *binop = dyn_cast<llvm::BinaryOperator>(v)) {
                Value *LHS = binop->getOperand(0);
                Value *RHS = binop->getOperand(1);
                if (llvm::isa<ConstantInt>(LHS) && llvm::isa<ConstantInt>(RHS)) {
                    APInt LHSVal = dyn_cast<ConstantInt>(LHS)->getValue();
                    APInt RHSVal = dyn_cast<ConstantInt>(RHS)->getValue();
                    switch (binop->getOpcode()) {
                        case llvm::Instruction::Add:
                            if (LHSVal == 0) return RHS;
                            if (RHSVal == 0) return LHS;
                            break;
                        case llvm::Instruction::Sub:
                            if (RHSVal == 0) return LHS;
                            break;
                        case llvm::Instruction::Mul:
                            if (LHSVal == 1) return RHS;
                            if (RHSVal == 1) return LHS;
                            if (LHSVal == 0 || RHSVal == 0) return ConstantInt::get(LHS->getType(), 0);
                            break;
                        case llvm::Instruction::SDiv:
                            if (RHSVal == 1) return LHS;
                            break;
                        case llvm::Instruction::UDiv:
                            if (RHSVal == 1) return LHS;
                            break;
                        default:
                            break;
                    }

                }
                
            }

            if (llvm::BinaryOperator *binop = dyn_cast<llvm::BinaryOperator>(v)) {
                Value *LHS = binop->getOperand(0);
                Value *RHS = binop->getOperand(1);
                switch (binop->getOpcode()){
                    case llvm::Instruction::And:
                        if (llvm::isa<ConstantInt>(LHS) && llvm::isa<ConstantInt>(RHS)) {
                            ConstantInt *LHSInt = dyn_cast<ConstantInt>(LHS);
                            ConstantInt *RHSInt = dyn_cast<ConstantInt>(RHS);
                            if (LHSInt->isZero() || RHSInt->isZero()) return ConstantInt::getFalse(LHS->getType());
                            if (LHSInt->isOne() && RHSInt->isOne()) return ConstantInt::getTrue(LHS->getType());
                            if (LHSInt->isOne()) return RHS;
                            if (RHSInt->isOne()) return LHS;
                        }
                        break;
                    case llvm::Instruction::Or:
                        if (llvm::isa<ConstantInt>(LHS) && llvm::isa<ConstantInt>(RHS)) {
                            ConstantInt *LHSInt = dyn_cast<ConstantInt>(LHS);
                            ConstantInt *RHSInt = dyn_cast<ConstantInt>(RHS);
                            if (LHSInt->isZero() && RHSInt->isZero()) return ConstantInt::getFalse(LHS->getType());
                            if (LHSInt->isOne() || RHSInt->isOne()) return ConstantInt::getTrue(LHS->getType());
                            if (LHSInt->isZero()) return LHS;
                            if (RHSInt->isZero()) return RHS;
                        }
                        break;
                }
            }

            return nullptr;
        }
    };
}

char AlgebraicSimplification::ID = 1;

static RegisterPass<AlgebraicSimplification> X("algebraicsimplification", "Algebraic Simplification pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAlgebraicSimplificationPass(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new AlgebraicSimplification ());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerAlgebraicSimplificationPass);