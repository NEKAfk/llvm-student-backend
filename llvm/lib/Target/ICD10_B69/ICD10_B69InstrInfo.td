//===----------------------------------------------------------------------===//
// ICD10_B69 profiles and nodes
//===----------------------------------------------------------------------===//

def ICD10_B69_ret      : SDNode<"ICD10_B69ISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "ICD10_B69InstrFormats.td"

//===----------------------------------------------------------------------===//
// ICD10_B69 Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class SImmAsmOperand<int width> : AsmOperandClass {
  let Name = "SImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def simm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM16";
  let OperandNamespace = "ICD10_B69Op";
}

def simm24 : Operand<i32>, ImmLeaf<i32, [{return isInt<24>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<24>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<24>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<24>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM24";
  let OperandNamespace = "ICD10_B69Op";
}

//===----------------------------------------------------------------------===//
// ICD10_B69 Instructions
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// ICD10_B69 Instructions
//===----------------------------------------------------------------------===//

// Arithmetic Instructions
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in {
  def ADD : ICD10_B69Inst<0x10, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                          "ADD $rd, $rs1, $rs2",
                          [(set GPR:$rd, (add GPR:$rs1, GPR:$rs2))]>;
  
  def ADDi : ICD10_B69Inst<0x11, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                           "ADDi $rd, $rs1, $imm",
                           [(set GPR:$rd, (add GPR:$rs1, simm16:$imm))]>;
  
  def SUBi : ICD10_B69Inst<0x12, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                           "SUBi $rd, $rs1, $imm",
                           [(set GPR:$rd, (sub GPR:$rs1, simm16:$imm))]>;
  
  def MULi : ICD10_B69Inst<0x13, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                           "MULi $rd, $rs1, $imm",
                           [(set GPR:$rd, (mul GPR:$rs1, simm16:$imm))]>;
  
  def SHLi : ICD10_B69Inst<0x14, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                           "SHLi $rd, $rs1, $imm",
                           [(set GPR:$rd, (shl GPR:$rs1, (i32 simm16:$imm)))]>;
  
  def ANDi : ICD10_B69Inst<0x15, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                           "ANDi $rd, $rs1, $imm",
                           [(set GPR:$rd, (and GPR:$rs1, simm16:$imm))]>;
  
  def XOR : ICD10_B69Inst<0x16, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                          "XOR $rd, $rs1, $rs2",
                          [(set GPR:$rd, (xor GPR:$rs1, GPR:$rs2))]>;
  
  def XORi : ICD10_B69Inst<0x17, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                           "XORi $rd, $rs1, $imm",
                           [(set GPR:$rd, (xor GPR:$rs1, simm16:$imm))]>;
  
  def OR : ICD10_B69Inst<0x18, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                         "OR $rd, $rs1, $rs2",
                         [(set GPR:$rd, (or GPR:$rs1, GPR:$rs2))]>;
}

// Move Instructions
let isAsCheapAsAMove = 1, isReMaterializable = 1 in {
  def MOV : ICD10_B69Inst<0x20, (outs GPR:$rd), (ins GPR:$rs1),
                          "MOV $rd, $rs1",
                          [(set GPR:$rd, GPR:$rs1)]>;
  
  def MOVi : ICD10_B69Inst<0x21, (outs GPR:$rd), (ins simm16:$imm),
                           "MOVi $rd, $imm",
                           [(set GPR:$rd, simm16:$imm)]>;
}

// Compare Instructions
def ICMP_EQ : ICD10_B69Inst<0x30, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                            "ICMP_EQ $rd, $rs1, $imm",
                            [(set GPR:$rd, (seteq GPR:$rs1, simm16:$imm))]>;
  
def ICMP_NE : ICD10_B69Inst<0x31, (outs GPR:$rd), (ins GPR:$rs1, simm16:$imm),
                            "ICMP_NE $rd, $rs1, $imm",
                            [(set GPR:$rd, (setne GPR:$rs1, simm16:$imm))]>;

// Select Instructions
def SELECTii : ICD10_B69Inst<0x32, (outs GPR:$rd), (ins GPR:$rc, simm24:$imm_true, simm16:$imm_false),
                             "SELECTii $rd, $rc, $imm_true, $imm_false",
                             [(set GPR:$rd, (select (i1 (trunc GPR:$rc)), simm24:$imm_true, simm16:$imm_false))]>;
  
def SELECTri : ICD10_B69Inst<0x33, (outs GPR:$rd), (ins GPR:$rc, GPR:$rs1, simm16:$imm_false),
                             "SELECTri $rd, $rc, $rs1, $imm_false",
                             [(set GPR:$rd, (select (i1 (trunc GPR:$rc)), GPR:$rs1, simm16:$imm_false))]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : ICD10_B69Inst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                  [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : ICD10_B69PseudoInst<(outs), (ins), "# PseudoRET",
                [(ICD10_B69_ret)]>,
                PseudoInstExpansion<(BR R0)>;