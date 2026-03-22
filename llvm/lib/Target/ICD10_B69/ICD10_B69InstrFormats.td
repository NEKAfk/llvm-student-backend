//===----------------------------------------------------------------------===//
//  Describe ICD10_B69 instructions format
//
//  CPU INSTRUCTION FORMATS
//
//  FF FF FF FF FF FF FF FF 
//                    ^^ ^^ - r5_imm - fifth reg or imm
//           ^^ ^^ ^^       - r4_imm - fourth reg or imm
//         ^                - reserved, should be 0
//        ^                 - r3     - third reg
//      ^                   - r2     - second reg
//     ^                    - r1     - first reg
//  ^^                      - opcode - operation code
//
//===----------------------------------------------------------------------===//

// Generic ICD10_B69 Format
class ICD10_B69Inst<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "ICD10_B69";
  let DecoderNamespace = "ICD10_B69";
  let Size = 8;

  field bits<64> Inst;

  bits<8> Opcode = op;
  bits<4>  r1 = 0;
  bits<4>  r2 = 0;
  bits<4>  r3 = 0;
  bits<24> r4_imm = 0;
  bits<16> r5_imm = 0;

  let Inst{63-56} = Opcode;
  let Inst{55-52} = r1;
  let Inst{51-48} = r2;
  let Inst{47-44} = r3;
  let Inst{43-40} = 0;
  let Inst{39-16} = r4_imm;
  let Inst{15-0}  = r5_imm;

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;

}

// Pseudo instructions format
class ICD10_B69PseudoInst<dag outs, dag ins, string asmstr, list<dag> pattern>
   : ICD10_B69Inst<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}