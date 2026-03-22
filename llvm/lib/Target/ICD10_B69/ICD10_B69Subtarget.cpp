#include "ICD10_B69Subtarget.h"
#include "ICD10_B69.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "icd10_b69-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ICD10_B69GenSubtargetInfo.inc"

ICD10_B69Subtarget::ICD10_B69Subtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const TargetMachine &TM)
    : ICD10_B69GenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this), InstrInfo() {
  ICD10_B69_DUMP_CYAN
}