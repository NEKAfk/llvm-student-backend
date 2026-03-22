add_llvm_component_group(ICD10_B69)

set(LLVM_TARGET_DEFINITIONS ICD10_B69.td)

tablegen(LLVM ICD10_B69GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM ICD10_B69GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM ICD10_B69GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM ICD10_B69GenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM ICD10_B69GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM ICD10_B69GenCallingConv.inc -gen-callingconv)

add_public_tablegen_target(ICD10_B69CommonTableGen)

add_llvm_target(ICD10_B69CodeGen
  ICD10_B69TargetMachine.cpp
  ICD10_B69RegisterInfo.cpp
  ICD10_B69InstrInfo.cpp
  ICD10_B69Subtarget.cpp
  ICD10_B69AsmPrinter.cpp
  ICD10_B69ISelDagToDag.cpp
  ICD10_B69ISelLowering.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ICD10_B69Info
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  ICD10_B69
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)