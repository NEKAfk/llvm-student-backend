#include "ICD10_B69InstrInfo.h"
#include "ICD10_B69.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "ICD10_B69GenInstrInfo.inc"

#define DEBUG_TYPE "ICD10_B69-inst-info"

ICD10_B69InstrInfo::ICD10_B69InstrInfo() : ICD10_B69GenInstrInfo() { ICD10_B69_DUMP_GREEN }