#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69FRAMELOWERING_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69FRAMELOWERING_H

#include "ICD10_B69.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class ICD10_B69Subtarget;

class ICD10_B69FrameLowering : public TargetFrameLowering {
public:
  ICD10_B69FrameLowering(const ICD10_B69Subtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(8), 0),
        STI(STI) {
    ICD10_B69_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }

private:
  const ICD10_B69Subtarget &STI;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69FRAMELOWERING_H