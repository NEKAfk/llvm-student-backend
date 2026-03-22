include "llvm/Target/Target.td"
include "ICD10_B69RegisterInfo.td"
include "ICD10_B69InstrInfo.td"

def ICD10_B69InstrInfo : InstrInfo;
def ICD10_B69 : Target {
  let InstructionSet = ICD10_B69InstrInfo;
}