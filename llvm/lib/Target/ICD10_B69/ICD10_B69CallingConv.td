//===----------------------------------------------------------------------===//
 // This describes the calling conventions for ICD10_B69 architecture.
 //===----------------------------------------------------------------------===//
 
 //===----------------------------------------------------------------------===//
 // ICD10_B69 Return Value Calling Convention
 //===----------------------------------------------------------------------===//
 def RetCC_ICD10_B69 : CallingConv<[
   // i64 return values
   CCIfType<[i32, i64], CCAssignToReg<[R9, R10, R11, R12]>>,
 
   // Integer values get stored in stack slots that are 4 bytes in
   // size and 8-byte aligned.
   CCIfType<[i64], CCAssignToStack<8, 8>>,
   CCIfType<[i32], CCAssignToStack<4, 8>>
 ]>;
 
 //===----------------------------------------------------------------------===//
 // ICD10_B69 Argument Calling Conventions
 //===----------------------------------------------------------------------===//
 def CC_ICD10_B69 : CallingConv<[
   // Promote i8/i16 arguments to i64.
   CCIfType<[i8, i16], CCPromoteToType<i32>>,
 
   // The first 4 integer arguments are passed in integer registers.
   CCIfType<[i32, i64], CCAssignToReg<[R9, R10, R11, R12]>>,
 
   // Integer values get stored in stack slots that are 4 bytes in
   // size and 8-byte aligned.
   CCIfType<[i64], CCAssignToStack<8, 8>>,
   CCIfType<[i32], CCAssignToStack<4, 8>>
 ]>;
 
 def CSR_ICD10_B69 : CalleeSavedRegs<(add R0, R1, R2, R3, R6, R7, R8)>;