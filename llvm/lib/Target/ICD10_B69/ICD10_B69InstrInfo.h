#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69INSTRINFO_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69INSTRINFO_H

#include "ICD10_B69RegisterInfo.h"
#include "MCTargetDesc/ICD10_B69Info.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "ICD10_B69GenInstrInfo.inc"

namespace llvm {

class ICD10_B69Subtarget;

class ICD10_B69InstrInfo : public ICD10_B69GenInstrInfo {
public:
  ICD10_B69InstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69INSTRINFO_H