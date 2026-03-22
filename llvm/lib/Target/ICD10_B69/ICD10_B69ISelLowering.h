#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69ISELLOWERING_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69ISELLOWERING_H

#include "ICD10_B69.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class ICD10_B69Subtarget;
class ICD10_B69TargetMachine;

namespace ICD10_B69ISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  JMP
};

} // namespace ICD10_B69ISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69ISELLOWERING_H