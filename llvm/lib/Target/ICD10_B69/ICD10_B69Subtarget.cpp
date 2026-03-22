#include "ICD10_B69Subtarget.h"
#include "ICD10_B69.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "icd10_b69-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ICD10_B69GenSubtargetInfo.inc"

ICD10_B69Subtarget::ICD10_B69Subtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : ICD10_B69GenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  ICD10_B69_DUMP_CYAN
}