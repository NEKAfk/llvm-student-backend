add_llvm_component_library(LLVMICD10_B69Desc
  ICD10_B69MCTargetDesc.cpp
  ICD10_B69MCAsmInfo.cpp
  ICD10_B69InstPrinter.cpp
  ICD10_B69MCCodeEmitter.cpp
  ICD10_B69AsmBackend.cpp
  ICD10_B69ELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  ICD10_B69Info

  ADD_TO_COMPONENT
  ICD10_B69
 )