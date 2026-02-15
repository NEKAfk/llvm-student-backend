#include "TargetInfo/ICD10_B69TargetInfo.h"
#include "ICD10_B69.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheICD10_B69Target() {
  ICD10_B69_DUMP_YELLOW
  static Target TheICD10_B69Target;
  return TheICD10_B69Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeICD10_B69TargetInfo() {
  ICD10_B69_DUMP_YELLOW
  RegisterTarget<Triple::icd10_b69> X(getTheICD10_B69Target(), "icd10_b69",
                                "Simulator target for LLVM course", "ICD10_B69");
}