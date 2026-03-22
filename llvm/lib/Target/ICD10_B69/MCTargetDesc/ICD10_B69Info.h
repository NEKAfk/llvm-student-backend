#ifndef LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69INFO_H
#define LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69INFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace ICD10_B69Op {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
  OPERAND_SIMM24
};
} // namespace ICD10_B69Op

} // end namespace llvm

#endif