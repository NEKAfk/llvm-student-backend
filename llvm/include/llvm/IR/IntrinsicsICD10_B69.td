let TargetPrefix = "icd10b69" in {  // All intrinsics start with "llvm.icd10b69.".
 
 def int_icd10b69_putpixel:
   Intrinsic<[], [llvm_i64_ty, llvm_i64_ty, llvm_i64_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_icd10b69_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 def int_icd10b69_rndmod:
   Intrinsic<[llvm_i64_ty], [llvm_i64_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "icd10b69"