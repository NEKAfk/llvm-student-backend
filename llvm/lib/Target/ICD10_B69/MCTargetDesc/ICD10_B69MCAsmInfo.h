#ifndef LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69MCASMINFO_H
#define LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69MCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class ICD10_B69ELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit ICD10_B69ELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_MCTARGETDESC_ICD10_B69MCASMINFO_H