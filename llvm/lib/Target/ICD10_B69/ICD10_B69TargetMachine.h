#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69TARGETMACHINE_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69TARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheICD10_B69Target;

class ICD10_B69TargetMachine : public CodeGenTargetMachineImpl {
public:
  ICD10_B69TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69TARGETMACHINE_H