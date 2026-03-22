#ifndef LLVM_LIB_TARGET_ICD10_B69_ICD10_B69_H
#define LLVM_LIB_TARGET_ICD10_B69_ICD10_B69_H

#include "MCTargetDesc/ICD10_B69MCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define ICD10_B69_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define ICD10_B69_DUMP(Color) {}

#define ICD10_B69_DUMP_RED ICD10_B69_DUMP(llvm::raw_ostream::RED)
#define ICD10_B69_DUMP_GREEN ICD10_B69_DUMP(llvm::raw_ostream::GREEN)
#define ICD10_B69_DUMP_YELLOW ICD10_B69_DUMP(llvm::raw_ostream::YELLOW)
#define ICD10_B69_DUMP_CYAN ICD10_B69_DUMP(llvm::raw_ostream::CYAN)
#define ICD10_B69_DUMP_MAGENTA ICD10_B69_DUMP(llvm::raw_ostream::MAGENTA)
#define ICD10_B69_DUMP_WHITE ICD10_B69_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class ICD10_B69TargetMachine;
class FunctionPass;

FunctionPass *createICD10_B69ISelDag(ICD10_B69TargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_ICD10_B69_ICD10_B69_H