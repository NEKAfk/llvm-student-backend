#include "MCTargetDesc/ICD10_B69Info.h"
#include "ICD10_B69.h"
#include "ICD10_B69InstPrinter.h"
#include "ICD10_B69MCAsmInfo.h"
#include "TargetInfo/ICD10_B69TargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ICD10_B69GenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ICD10_B69GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "ICD10_B69GenSubtargetInfo.inc"

static MCRegisterInfo *createICD10_B69MCRegisterInfo(const Triple &TT) {
  ICD10_B69_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitICD10_B69MCRegisterInfo(X, ICD10_B69::R0);
  return X;
}

static MCInstrInfo *createICD10_B69MCInstrInfo() {
  ICD10_B69_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitICD10_B69MCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createICD10_B69MCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  ICD10_B69_DUMP_MAGENTA
  return createICD10_B69MCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createICD10_B69MCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  ICD10_B69_DUMP_MAGENTA
  MCAsmInfo *MAI = new ICD10_B69ELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(ICD10_B69::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createICD10_B69MCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  ICD10_B69_DUMP_MAGENTA
  return new ICD10_B69InstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeICD10_B69TargetMC() {
  ICD10_B69_DUMP_MAGENTA
  Target &TheICD10_B69Target = getTheICD10_B69Target();
  RegisterMCAsmInfoFn X(TheICD10_B69Target, createICD10_B69MCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheICD10_B69Target, createICD10_B69MCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheICD10_B69Target, createICD10_B69MCInstrInfo);
    // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheICD10_B69Target,
                                          createICD10_B69MCSubtargetInfo);
  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheICD10_B69Target, createICD10_B69MCInstPrinter);
}