#include "ICD10_B69.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void ICD10_B69TargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__icd10_b69__");
}

ArrayRef<Builtin::Info> ICD10_B69TargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}