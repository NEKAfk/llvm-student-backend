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

const MCPhysReg *
ICD10_B69RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  ICD10_B69_DUMP_GREEN
  return CSR_ICD10_B69_SaveList;
}

BitVector ICD10_B69RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  ICD10_B69_DUMP_GREEN
  ICD10_B69FrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(ICD10_B69::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(ICD10_B69::R2);
  }
  return Reserved;
}

bool ICD10_B69RegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool ICD10_B69RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  ICD10_B69_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register ICD10_B69RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  ICD10_B69_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? ICD10_B69::R2 : ICD10_B69::R1;
}

const uint32_t *
ICD10_B69RegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  ICD10_B69_DUMP_GREEN
  return CSR_ICD10_B69_RegMask;
}