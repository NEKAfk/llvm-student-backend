#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69REGISTERINFO_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69REGISTERINFO_H

#define GET_REGINFO_HEADER
#include "ICD10_B69GenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class ICD10_B69Subtarget;

struct ICD10_B69RegisterInfo : public ICD10_B69GenRegisterInfo {
public:
  ICD10_B69RegisterInfo();

  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;

  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID CC) const override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool requiresRegisterScavenging(const MachineFunction &MF) const override;

  bool eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;

  // Debug information queries.
  Register getFrameRegister(const MachineFunction &MF) const override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69REGISTERINFO_H