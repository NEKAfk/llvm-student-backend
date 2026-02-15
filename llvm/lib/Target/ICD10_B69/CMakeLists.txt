add_llvm_component_group(ICD10_B69)

add_llvm_target(ICD10_B69CodeGen
  ICD10_B69TargetMachine.cpp

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