let TargetPrefix = "icd10b69" in {  // All intrinsics start with "llvm.icd10b69.".
 
 def int_icd10b69_putpixel: ClangBuiltin<"simPutPixel">,
   Intrinsic<[], [llvm_i64_ty, llvm_i64_ty, llvm_i64_ty], [IntrNoMem, IntrHasSideEffects]>;

 def int_icd10b69_flush: ClangBuiltin<"simFlush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 def int_icd10b69_rndmod: ClangBuiltin<"simRndMod">,
   Intrinsic<[llvm_i64_ty], [llvm_i64_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "icd10b69"