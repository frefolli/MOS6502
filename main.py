values = [
  ('ADC_imm', 0x69),
  ('ADC_X_ind', 0x61),
  ('ADC_abs', 0x6d),
  ('ADC_abs_X', 0x7d),
  ('ADC_abs_Y', 0x79),
  ('ADC_ind_Y', 0x71),
  ('ADC_zpg', 0x65),
  ('ADC_zpg_X', 0x75),
  ('AND_imm', 0x29),
  ('AND_X_ind', 0x21),
  ('AND_abs', 0x2d),
  ('AND_abs_X', 0x3d),
  ('AND_abs_Y', 0x39),
  ('AND_ind_Y', 0x31),
  ('AND_zpg', 0x25),
  ('AND_zpg_X', 0x35),
  ('ASL_A', 0xa),
  ('ASL_abs', 0xe),
  ('ASL_abs_X', 0x1e),
  ('ASL_zpg', 0x6),
  ('ASL_zpg_X', 0x16),
  ('BCC_rel', 0x90),
  ('BCS_rel', 0xb0),
  ('BEQ_rel', 0xf0),
  ('BIT_abs', 0x2c),
  ('BIT_zpg', 0x24),
  ('BMI_rel', 0x30),
  ('BNE_rel', 0xd0),
  ('BPL_rel', 0x10),
  ('BRK_impl', 0x0),
  ('BVC_rel', 0x50),
  ('BVS_rel', 0x70),
  ('CLC_impl', 0x18),
  ('CLD_impl', 0xd8),
  ('CLI_impl', 0x58),
  ('CLV_impl', 0xb8),
  ('CMP_imm', 0xc9),
  ('CMP_X_ind', 0xc1),
  ('CMP_abs', 0xcd),
  ('CMP_abs_X', 0xdd),
  ('CMP_abs_Y', 0xd9),
  ('CMP_ind_Y', 0xd1),
  ('CMP_zpg', 0xc5),
  ('CMP_zpg_X', 0xd5),
  ('CPX_imm', 0xe0),
  ('CPX_abs', 0xec),
  ('CPX_zpg', 0xe4),
  ('CPY_imm', 0xc0),
  ('CPY_abs', 0xcc),
  ('CPY_zpg', 0xc4),
  ('DEC_abs', 0xce),
  ('DEC_abs_X', 0xde),
  ('DEC_zpg', 0xc6),
  ('DEC_zpg_X', 0xd6),
  ('DEX_impl', 0xca),
  ('DEY_impl', 0x88),
  ('EOR_imm', 0x49),
  ('EOR_X_ind', 0x41),
  ('EOR_abs', 0x4d),
  ('EOR_abs_X', 0x5d),
  ('EOR_abs_Y', 0x59),
  ('EOR_ind_Y', 0x51),
  ('EOR_zpg', 0x45),
  ('EOR_zpg_X', 0x55),
  ('INC_abs', 0xee),
  ('INC_abs_X', 0xfe),
  ('INC_zpg', 0xe6),
  ('INC_zpg_X', 0xf6),
  ('INX_impl', 0xe8),
  ('INY_impl', 0xc8),
  ('JMP_abs', 0x4c),
  ('JMP_ind', 0x6c),
  ('JSR_abs', 0x20),
  ('LDA_imm', 0xa9),
  ('LDA_X_ind', 0xa1),
  ('LDA_abs', 0xad),
  ('LDA_abs_X', 0xbd),
  ('LDA_abs_Y', 0xb9),
  ('LDA_ind_Y', 0xb1),
  ('LDA_zpg', 0xa5),
  ('LDA_zpg_X', 0xb5),
  ('LDX_imm', 0xa2),
  ('LDX_abs', 0xae),
  ('LDX_abs_Y', 0xbe),
  ('LDX_zpg', 0xa6),
  ('LDX_zpg_Y', 0xb6),
  ('LDY_imm', 0xa0),
  ('LDY_abs', 0xac),
  ('LDY_abs_X', 0xbc),
  ('LDY_zpg', 0xa4),
  ('LDY_zpg_X', 0xb4),
  ('LSR_A', 0x4a),
  ('LSR_abs', 0x4e),
  ('LSR_abs_X', 0x5e),
  ('LSR_zpg', 0x46),
  ('LSR_zpg_X', 0x56),
  ('NOP_impl', 0xea),
  ('ORA_imm', 0x9),
  ('ORA_X_ind', 0x1),
  ('ORA_abs', 0xd),
  ('ORA_abs_X', 0x1d),
  ('ORA_abs_Y', 0x19),
  ('ORA_ind_Y', 0x11),
  ('ORA_zpg', 0x5),
  ('ORA_zpg_X', 0x15),
  ('PHA_impl', 0x48),
  ('PHP_impl', 0x8),
  ('PLA_impl', 0x68),
  ('PLP_impl', 0x28),
  ('ROL_A', 0x2a),
  ('ROL_abs', 0x2e),
  ('ROL_abs_X', 0x3e),
  ('ROL_zpg', 0x26),
  ('ROL_zpg_X', 0x36),
  ('ROR_A', 0x6a),
  ('ROR_abs', 0x6e),
  ('ROR_abs_X', 0x7e),
  ('ROR_zpg', 0x66),
  ('ROR_zpg_X', 0x76),
  ('RTI_impl', 0x40),
  ('RTS_impl', 0x60),
  ('SBC_imm', 0xe9),
  ('SBC_X_ind', 0xe1),
  ('SBC_abs', 0xed),
  ('SBC_abs_X', 0xfd),
  ('SBC_abs_Y', 0xf9),
  ('SBC_ind_Y', 0xf1),
  ('SBC_zpg', 0xe5),
  ('SBC_zpg_X', 0xf5),
  ('SEC_impl', 0x38),
  ('SED_impl', 0xf8),
  ('SEI_impl', 0x78),
  ('STA_X_ind', 0x81),
  ('STA_abs', 0x8d),
  ('STA_abs_X', 0x9d),
  ('STA_abs_Y', 0x99),
  ('STA_ind_Y', 0x91),
  ('STA_zpg', 0x85),
  ('STA_zpg_X', 0x95),
  ('STX_abs', 0x8e),
  ('STX_zpg', 0x86),
  ('STX_zpg_Y', 0x96),
  ('STY_abs', 0x8c),
  ('STY_zpg', 0x84),
  ('STY_zpg_X', 0x94),
  ('TAX_impl', 0xaa),
  ('TAY_impl', 0xa8),
  ('TSX_impl', 0xba),
  ('TXA_impl', 0x8a),
  ('TXS_impl', 0x9a),
  ('TYA_impl', 0x98),
]

for (name, value) in values:
  filepath = "./tests/%s.c" % name
  with open(filepath, mode="w") as file:
    file.write("#include <vm/vm.h>\n")
    file.write("#include <vm/opcodes.h>\n")
    file.write("\n")
    file.write("int main(void) {\n")
    file.write("  struct VM vm;\n")
    file.write("  VM__clear(&vm);\n")
    file.write("  VM__reset(&vm);\n")
    file.write("  vm.mem[0] = %s;\n" % name)
    file.write("  vm.mem[1] = 0x00;\n")
    file.write("  VM__step(&vm);\n")
    file.write("}\n")

for (name, value) in values:
  filepath = "./src/vm/%s.c" % name
  with open(filepath, mode="w") as file:
    file.write("#include <vm/%s.h>\n" % name)
    file.write("#include <vm/macros.h>\n")
    file.write("#include <vm/addressing.h>\n")
    file.write("\n")
    file.write("void VM__%s(struct VM* vm) {\n" % (name, ))
    file.write("  TODO();\n")
    file.write("}\n")

for (name, value) in values:
  filepath = "./include/vm/%s.h" % name
  with open(filepath, mode="w") as file:
    label = ("VM_%s_H" % name).upper()
    file.write("#ifndef %s\n" % label)
    file.write("#define %s\n" % label)
    file.write("#include <vm/vm.h>\n")
    file.write("\n")
    file.write("void VM__%s(struct VM* vm);\n" % (name, ))
    file.write("#endif//%s\n" % label)

filepath = "./include/vm/opcodes.h"
with open(filepath, mode="w") as file:
  label = "VM_OPCODES_H"
  file.write("#ifndef %s\n" % label)
  file.write("#define %s\n" % label)
  file.write("typedef enum {\n")
  for (name, value) in values:
    file.write("  %s = %s,\n" % (name, hex(value)))
  file.write("} VM_OPCODES;\n")
  file.write("#endif//%s\n" % label)

filepath = "./include/vm/instructions.h"
with open(filepath, mode="w") as file:
  label = "VM_INSTRUCTIONS_H"
  file.write("#ifndef %s\n" % label)
  file.write("#define %s\n" % label)
  for (name, value) in values:
    file.write('#include <vm/%s.h>\n' % name)
  file.write("#endif//%s\n" % label)

filepath = "./tests/meson.build"
with open(filepath, mode="w") as file:
  for (name, value) in values:
    file.write("test_%s = executable('test_%s', [\n" % (name, name))
    file.write("    './%s.c',\n" % (name,))
    file.write("  ], install : false,\n")
    file.write("  include_directories: ['../include'],\n")
    file.write("  link_with: libvm)\n")
    file.write("test('%s', test_%s)\n" % (name, name))
    file.write("\n")
