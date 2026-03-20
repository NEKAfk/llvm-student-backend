#include "ICD10_B69.h"
#include "TargetInfo/ICD10_B69TargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ICD10_B69GenRegisterInfo.inc"

static MCRegisterInfo *createICD10_B69MCRegisterInfo(const Triple &TT) {
  ICD10_B69_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitICD10_B69MCRegisterInfo(X, ICD10_B69::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeICD10_B69TargetMC() {
  ICD10_B69_DUMP_MAGENTA
  Target &TheICD10_B69Target = getTheICD10_B69Target();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheICD10_B69Target, createICD10_B69MCRegisterInfo);
}