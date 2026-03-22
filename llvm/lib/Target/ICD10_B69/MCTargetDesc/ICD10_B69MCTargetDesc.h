#ifndef LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69MCTARGETDESC_H
#define LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69MCTARGETDESC_H

// Defines symbolic names for ICD10_B69 registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "ICD10_B69GenRegisterInfo.inc"

// Defines symbolic names for the ICD10_B69 instructions.
#define GET_INSTRINFO_ENUM
#include "ICD10_B69GenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69MCTARGETDESC_H