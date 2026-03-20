#include "ICD10_B69RegisterInfo.h"
#include "ICD10_B69.h"
#include "ICD10_B69FrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ICD10_B69GenRegisterInfo.inc"

ICD10_B69RegisterInfo::ICD10_B69RegisterInfo() : ICD10_B69GenRegisterInfo(ICD10_B69::R0) {
  ICD10_B69_DUMP_GREEN
}