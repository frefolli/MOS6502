#include <assert.h>
#include <stdio.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  uint64_t a = 0x1122334455667788, b = 0x8877665544332211;
  uint64_t c = a - b;
  uint8_t program[] = {
    // i = 0
    LDA_imm, 0,
    STA_zpg, 0x00,
    LDA_imm, 0,
    STA_zpg, 0x01,
    // a
    LDX_imm, (a & 0xff),
    STX_zpg, 0x02,
    LDX_imm, ((a >> 8 * 1) & 0xff),
    STX_zpg, 0x03,
    LDX_imm, ((a >> 8 * 2) & 0xff),
    STX_zpg, 0x04,
    LDX_imm, ((a >> 8 * 3) & 0xff),
    STX_zpg, 0x05,
    LDX_imm, ((a >> 8 * 4) & 0xff),
    STX_zpg, 0x06,
    LDX_imm, ((a >> 8 * 5) & 0xff),
    STX_zpg, 0x07,
    LDX_imm, ((a >> 8 * 6) & 0xff),
    STX_zpg, 0x08,
    LDX_imm, ((a >> 8 * 7) & 0xff),
    STX_zpg, 0x09,
    // b
    LDX_imm, (b & 0xff),
    STX_zpg, 0x0a,
    LDX_imm, ((b >> 8 * 1) & 0xff),
    STX_zpg, 0x0b,
    LDX_imm, ((b >> 8 * 2) & 0xff),
    STX_zpg, 0x0c,
    LDX_imm, ((b >> 8 * 3) & 0xff),
    STX_zpg, 0x0d,
    LDX_imm, ((b >> 8 * 4) & 0xff),
    STX_zpg, 0x0e,
    LDX_imm, ((b >> 8 * 5) & 0xff),
    STX_zpg, 0x0f,
    LDX_imm, ((b >> 8 * 6) & 0xff),
    STX_zpg, 0x10,
    LDX_imm, ((b >> 8 * 7) & 0xff),
    STX_zpg, 0x11,
    SEC_impl,
    // c{i}: a{i} + b{i}
    LDY_imm, 0x02,
    LDA_ind_Y, 0x00,
    LDY_imm, 0x0a,
    SBC_ind_Y, 0x00,
    LDY_imm, 0x12,
    STA_ind_Y, 0x00,
    // cycle over i
    PHP_impl,
    INC_zpg, 0x00,
    LDA_imm, 0x08,
    CMP_zpg, 0x00,
    BNE_rel, -0x15,
    PLP_impl,
  };
  uint16_t program_length = sizeof(program) / sizeof(uint8_t);
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, program_length);
  uint16_t end_of_program = vm.PC + program_length;
  while (vm.PC < end_of_program) {
    VM__step(&vm);
  }
  uint64_t d = (
    ((uint64_t)vm.mem[0x12 + 0] << (8 * 0)) + 
    ((uint64_t)vm.mem[0x12 + 1] << (8 * 1)) + 
    ((uint64_t)vm.mem[0x12 + 2] << (8 * 2)) + 
    ((uint64_t)vm.mem[0x12 + 3] << (8 * 3)) + 
    ((uint64_t)vm.mem[0x12 + 4] << (8 * 4)) + 
    ((uint64_t)vm.mem[0x12 + 5] << (8 * 5)) + 
    ((uint64_t)vm.mem[0x12 + 6] << (8 * 6)) + 
    ((uint64_t)vm.mem[0x12 + 7] << (8 * 7))
  );
  assert(c == d);
}
