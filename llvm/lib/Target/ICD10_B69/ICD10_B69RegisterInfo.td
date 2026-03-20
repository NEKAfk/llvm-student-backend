// Reg-file declaration
class ICD10_B69Reg<bits<16> Enc, string n> : Register<n>{
    let HWEncoding = Enc;
    let Namespace = "ICD10_B69";
}

// Registers
foreach I = 0-15 in {
    def R#I : ICD10_B69Reg<I, "r"#I>;
}

// Classes
// General Purpose Regs
def GPR : RegisterClass<"ICD10_B69", [i32], 32, (add
  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15)>;