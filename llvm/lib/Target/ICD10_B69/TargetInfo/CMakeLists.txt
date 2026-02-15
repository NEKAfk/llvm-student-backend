
add_llvm_component_library(LLVMICD10_B69Info
  ICD10_B69TargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  ICD10_B69
  )