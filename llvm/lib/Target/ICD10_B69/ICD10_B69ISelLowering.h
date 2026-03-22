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
  CALL,
  JMP
};

} // namespace ICD10_B69ISD

class ICD10_B69TargetLowering : public TargetLowering {
public:
  explicit ICD10_B69TargetLowering(const TargetMachine &TM, const ICD10_B69Subtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  ICD10_B69Subtarget const &getSubtarget() const { return STI; }

private:
  const ICD10_B69Subtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69ISELLOWERING_H