#include "ICD10_B69ISelLowering.h"
#include "ICD10_B69.h"
#include "ICD10_B69RegisterInfo.h"
#include "ICD10_B69Subtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "icd10_b69-lower"

using namespace llvm;

ICD10_B69TargetLowering::ICD10_B69TargetLowering(const TargetMachine &TM,
                                     const ICD10_B69Subtarget &STI)
    : TargetLowering(TM), STI(STI) {
  ICD10_B69_DUMP_RED
  addRegisterClass(MVT::i32, &ICD10_B69::GPRRegClass);
}

const char *ICD10_B69TargetLowering::getTargetNodeName(unsigned Opcode) const {
  ICD10_B69_DUMP_RED
  switch (Opcode) {
  case ICD10_B69ISD::CALL:
    return "ICD10_B69ISD::CALL";
  case ICD10_B69ISD::RET:
    return "ICD10_B69ISD::RET";
  }
  return nullptr;
}