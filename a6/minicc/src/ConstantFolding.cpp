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
    struct ConstantFolding  : public FunctionPass {
        static char ID;
        ConstantFolding() : FunctionPass(ID) {}

        virtual bool runOnFunction(Function &F) {
            errs() << "Constant Folding Working on function called " << F.getName() << "!\n";

            bool changed = true;
            while (changed){
                changed = false;
                for (auto it = F.begin(); it != F.end(); it++) {
                    BasicBlock *bb = &*it;
                    for (auto it2 = bb->begin(); it2 != bb->end(); it2++) {
                        Instruction *inst = &*it2;
                        if(inst->getNumOperands() == 2 && isa<ConstantInt>(inst->getOperand(0)) && isa<ConstantInt>(inst->getOperand(1))) {
                            Value *v = nullptr;
                            ConstantInt *op1 = dyn_cast<ConstantInt>(inst->getOperand(0));
                            ConstantInt *op2 = dyn_cast<ConstantInt>(inst->getOperand(1));
                            switch(inst->getOpcode()) {
                                case Instruction::Add:
                                    v = ConstantInt::get(op1->getType(), op1->getValue() + op2->getValue());
                                    break;
                                case Instruction::Sub:
                                    v = ConstantInt::get(op1->getType(), op1->getValue() - op2->getValue());
                                    break;
                                case Instruction::Mul:
                                    v = ConstantInt::get(op1->getType(), op1->getValue() * op2->getValue());
                                    break;
                                case Instruction::SDiv:
                                    v = ConstantInt::get(op1->getType(), op1->getValue().sdiv(op2->getValue()));
                                    break;
                                case Instruction::UDiv:
                                    v = ConstantInt::get(op1->getType(), op1->getValue().udiv(op2->getValue()));
                                    break;
                                default:
                                    break;
                            }
                            if (v) {
                                inst->replaceAllUsesWith(v);
                                inst->eraseFromParent();
                                changed = true;
                                break;
                            }
                        }
                    
                    }
                }
            }
            return changed;
            
        }


        
    };
}

char ConstantFolding::ID = 1;

static RegisterPass<ConstantFolding> X("constantfolding", "Constant Folding pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerConstantFoldingPass(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new ConstantFolding());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerConstantFoldingPass);