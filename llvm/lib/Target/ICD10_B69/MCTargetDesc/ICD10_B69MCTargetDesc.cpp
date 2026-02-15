#include "../ICD10_B69.h"
#include "llvm/Support/raw_ostream.h"

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeICD10_B69TargetMC() { ICD10_B69_DUMP_MAGENTA }