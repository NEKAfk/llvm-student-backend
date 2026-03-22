#include "ICD10_B69TargetMachine.h"
#include "ICD10_B69.h"
#include "TargetInfo/ICD10_B69TargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeICD10_B69Target() {
  // Register the target.
  ICD10_B69_DUMP_CYAN
  RegisterTargetMachine<ICD10_B69TargetMachine> A(getTheICD10_B69Target());
}

ICD10_B69TargetMachine::ICD10_B69TargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  ICD10_B69_DUMP_CYAN
  initAsmInfo();
}


namespace {

/// ICD10_B69 Code Generator Pass Configuration Options.
class ICD10_B69PassConfig : public TargetPassConfig {
public:
  ICD10_B69PassConfig(ICD10_B69TargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}
  
  ICD10_B69TargetMachine &getICD10_B69TargetMachine() const {
    return getTM<ICD10_B69TargetMachine>();
  }

  bool addInstSelector() override {
    ICD10_B69_DUMP_CYAN
    addPass(createICD10_B69ISelDag(getICD10_B69TargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *ICD10_B69TargetMachine::createPassConfig(PassManagerBase &PM) {
  ICD10_B69_DUMP_CYAN
  return new ICD10_B69PassConfig(*this, PM);
}