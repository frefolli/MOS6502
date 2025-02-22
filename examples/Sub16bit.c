#include <assert.h>
#include <stdio.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  uint16_t a = 0x4321, b = 0xf234;
  uint16_t c = a - b;
  uint8_t program[] = {
    // Setup zpg
    // a: 0x12
    LDX_imm, (a & 0xff),
    STX_zpg, 0x00,
    LDX_imm, ((a >> 8) & 0xff),
    STX_zpg, 0x01,
    // b: 0x2f
    LDY_imm, (b & 0xff),
    STY_zpg, 0x02,
    LDY_imm, ((b >> 8) & 0xff),
    STY_zpg, 0x03,
    // Setup carry flag
    // c: a + b
    SEC_impl,
    LDA_zpg, 0x00,
    SBC_zpg, 0x02,
    STA_zpg, 0x04,
    LDA_zpg, 0x01,
    SBC_zpg, 0x03,
    STA_zpg, 0x05
  };
  uint16_t program_length = sizeof(program) / sizeof(uint8_t);
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, program_length);
  uint16_t end_of_program = vm.PC + program_length;
  while (vm.PC < end_of_program) {
    VM__step(&vm);
  }
  uint16_t d = (vm.mem[4]) + (vm.mem[5] << 8);
  assert(c == d);
}
