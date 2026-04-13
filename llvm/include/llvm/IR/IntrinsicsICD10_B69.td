let TargetPrefix = "icd10b69" in {  // All intrinsics start with "llvm.icd10b69.".
 
 def int_icd10b69_putpixel: ClangBuiltin<"putPixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

 def int_icd10b69_flush: ClangBuiltin<"flush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 def int_icd10b69_rndmod: ClangBuiltin<"randMod">,
   Intrinsic<[llvm_i32_ty], [llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "icd10b69"