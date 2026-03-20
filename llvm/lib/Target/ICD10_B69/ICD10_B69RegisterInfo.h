#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69REGISTERINFO_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69REGISTERINFO_H

#define GET_REGINFO_HEADER
#include "ICD10_B69GenRegisterInfo.inc"

namespace llvm {

struct ICD10_B69RegisterInfo : public ICD10_B69GenRegisterInfo {
public:
  ICD10_B69RegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69REGISTERINFO_H