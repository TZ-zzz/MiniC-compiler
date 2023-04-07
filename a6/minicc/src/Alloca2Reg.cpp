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
#include <set>
#include <map>

using namespace llvm;

namespace {
    struct Alloca2RegPass : public FunctionPass {
        static char ID;
        Alloca2RegPass() : FunctionPass(ID) {}

        //declare more varibles if you like
        std::set<AllocaInst*> TargetAllocas;
        std::map<BasicBlock*, std::map<AllocaInst*, Value*> > Post;
        std::map<BasicBlock*, std::map<AllocaInst*, PHINode*> > Pre;
        std::set<PHINode*> all_phi;

        void update_post(BasicBlock *bb, AllocaInst *ai, Value *v) {
            if (Post.find(bb) == Post.end()) {
                Post[bb] = std::map<AllocaInst*, Value*>();
            }
            Post[bb][ai] = v;
        }

        void update_pre(BasicBlock *bb, AllocaInst *ai, PHINode *v) {
            if (Pre.find(bb) == Pre.end()) {
                Pre[bb] = std::map<AllocaInst*, PHINode*>();
            }
            Pre[bb][ai] = v;
        }

        void collectTargetAllocas(Function &F) {
            //start your code here 
            for (auto it = F.begin(); it != F.end(); it++) {
                BasicBlock *bb = &*it;
                for (auto it2 = bb->begin(); it2 != bb->end(); it2++) {\
                    Instruction *inst = &*it2;
                    if (AllocaInst *alloca = dyn_cast<AllocaInst>(it2)) {
                        // for the pointer case, see piazza @434
                        if (!alloca->getAllocatedType()->isAggregateType()) {
                            TargetAllocas.insert(alloca);
                        }
                    }
               }
           }
        }

        Value *get_post(BasicBlock *bb, AllocaInst *ai) {
            if (Post.find(bb) == Post.end()) {
                return nullptr;
            }
            if (Post[bb].find(ai) == Post[bb].end()) {
                return nullptr;
            }
            return Post[bb][ai];
        }

        Value *get_pre(BasicBlock *bb, AllocaInst *ai) {
            if (Pre.find(bb) == Pre.end()) {
                return nullptr;
            }
            if (Pre[bb].find(ai) == Pre[bb].end()) {
                return nullptr;
            }
            return Pre[bb][ai];
        }

        bool check_redundant(PHINode *phi) {
            if (phi->getNumIncomingValues() == 0) {
                phi->eraseFromParent();
                all_phi.erase(phi);
                return true;
            }
            if (phi->getNumIncomingValues() == 1) {
                phi->replaceAllUsesWith(phi->getIncomingValue(0));
                phi->eraseFromParent();
                all_phi.erase(phi);
                return true;
            }
            else {
                // try to remove incoming self referencing and undef value
                for (int i = 0; i < phi->getNumIncomingValues(); i++) {
                    if (llvm::isa<llvm::UndefValue>(phi->getIncomingValue(i)) || phi->getIncomingValue(i) == phi) {
                        phi->removeIncomingValue(i, false);
                        if (phi->getNumIncomingValues() == 1) {
                            if (llvm::isa<llvm::UndefValue>(phi->getIncomingValue(0)) || phi->getIncomingValue(0) == phi) {
                                phi->eraseFromParent();
                                all_phi.erase(phi);
                                return true;
                            }
                            else {
                                phi->replaceAllUsesWith(phi->getIncomingValue(0));
                                phi->eraseFromParent();
                                all_phi.erase(phi);
                                return true;
                            }
                            return true;
                        }
                        else if (phi->getNumIncomingValues() == 0) {
                            phi->eraseFromParent();
                            all_phi.erase(phi);
                            return true;
                        }
                        else {
                            return false;
                        }
                        return true;
                    }
                }
                
                if (phi->hasConstantOrUndefValue()) {
                    if (llvm::isa<llvm::UndefValue>(phi->getIncomingValue(0))) {
                        phi->eraseFromParent();
                        all_phi.erase(phi);
                        return true;
                    }
                    else {
                        phi->replaceAllUsesWith(phi->getIncomingValue(0));
                        phi->eraseFromParent();
                        all_phi.erase(phi);
                        return true;
                    }
                }

            }
            return false;

        }

        virtual bool runOnFunction(Function &F) {
            errs() << "Working on function called " << F.getName() << "!\n";
            // step 1: Detect all alloca instructions that could be promoted.
            collectTargetAllocas(F);
            //start your code here

            // step 2
            std::set<Instruction *> all_inst;
            for (auto it = F.begin(); it != F.end(); it++) {
                BasicBlock *bb = &*it;
                if (bb != &F.getEntryBlock()) {
                    for (AllocaInst *ai : TargetAllocas) {
                        PHINode *phi = PHINode::Create(ai->getAllocatedType(), 0, "phi", bb->getFirstNonPHI());
                        for (BasicBlock *pred : llvm::predecessors(bb)) {
                            phi->addIncoming(llvm::UndefValue::get(ai->getAllocatedType()), pred);
                        }
                        update_pre(bb, ai, phi);
                        update_post(bb, ai, phi);
                        all_phi.insert(phi);
                    }
                }

                for (auto it = bb->begin(); it != bb->end(); it++) {
                    Instruction *inst = &*it;
                    if (llvm::isa<LoadInst>(inst)) {
                        llvm::Value *v = ((LoadInst *) inst)->getPointerOperand();
                        if (TargetAllocas.find((llvm::AllocaInst*)v) != TargetAllocas.end()) {
                            Value *value = get_post(bb, (llvm::AllocaInst *)v);
                            ((LoadInst *) inst)->replaceAllUsesWith(value);
                            all_inst.insert(inst);

                        }
                    }
                    else if (llvm::isa<StoreInst>(inst)) {
                        llvm::Value *v = ((StoreInst *) inst)->getPointerOperand();
                        if (TargetAllocas.find((llvm::AllocaInst *)v) != TargetAllocas.end()) {
                            Value *value = get_post(bb, (llvm::AllocaInst *)v);
                            if (value == nullptr) {
                                if (Post.find(bb) == Post.end()) {
                                    Post.insert(std::make_pair(bb, std::map<AllocaInst*, Value*>()));
                                }
                                Post[bb][(llvm::AllocaInst *)v] = ((StoreInst *) inst)->getValueOperand();
                                
                            }
                            else {
                                Post[bb][(llvm::AllocaInst *)v] = ((StoreInst *) inst)->getValueOperand();
                            }
                        all_inst.insert(inst);
                        }
                    }
                }
            }

            // step 3: Fill incoming edges of all created PHI instructions
            for (auto it = Pre.begin(); it != Pre.end(); it++) {
                BasicBlock *bb = it->first;
                for (auto it2 = Pre[bb].begin(); it2 != Pre[bb].end(); it2++) {
                    AllocaInst *ai = it2->first;
                    PHINode *phi = it2->second;
                    for (int i = 0; i < phi->getNumIncomingValues(); i++) {
                        BasicBlock *pred = phi->getIncomingBlock(i);
                        Value *value = get_post(pred, ai);
                        if (value){
                            phi->setIncomingValue(i, value);
                        }
                    }
                }
            }

            // step 4: Remove unused PHI instructions
            std::set <PHINode *> deleted_phi;
            for (auto it = all_phi.begin(); it != all_phi.end(); it++) {
                PHINode *phi = *it;
                if (phi->getNumUses() == 0) {
                    phi->eraseFromParent();
                    deleted_phi.insert(phi);
                }
            }
            for (auto it = deleted_phi.begin(); it != deleted_phi.end(); it++) {
                all_phi.erase(*it);
            }

            // step 5, 6: Remove all instructions that are no longer needed
            for (auto it = all_inst.begin(); it != all_inst.end(); it++) {
                Instruction *inst = *it;
                inst->eraseFromParent();
            }

            for (auto it = TargetAllocas.begin(); it != TargetAllocas.end(); it++) {
                AllocaInst *ai = *it;
                ai->eraseFromParent();
            }

            // step 7: Remove all PHI instructions that are no longer needed
            bool flag = true;
            while (flag) {
                flag = false;
                for (auto it = all_phi.begin(); it != all_phi.end(); it++) {
                    PHINode *phi = *it;
                    bool flag2 = check_redundant(phi);
                    if (flag2) {
                        flag = true;
                        break;
                    }

                }
            }

            TargetAllocas.clear();
            Pre.clear();
            Post.clear();
            all_phi.clear();
            all_inst.clear();
            deleted_phi.clear();


            return true;
        }
    };
}

char Alloca2RegPass::ID = 0;

static RegisterPass<Alloca2RegPass> X("alloca2reg", "Alloca-to-register pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAlloca2RegPass(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new Alloca2RegPass());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerAlloca2RegPass);