add_llvm_component_group(ICD10_B69)

set(LLVM_TARGET_DEFINITIONS ICD10_B69.td)

tablegen(LLVM ICD10_B69GenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(ICD10_B69CommonTableGen)

add_llvm_target(ICD10_B69CodeGen
  ICD10_B69TargetMachine.cpp
  ICD10_B69RegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ICD10_B69Info

  ADD_TO_COMPONENT
  ICD10_B69
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)