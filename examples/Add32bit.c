#include <assert.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  uint32_t a = 0x12344321, b = 0x7428f234;
  uint32_t c = a + b;
  uint8_t program[] = {
    // Setup zpg
    // a
    LDX_imm, (a & 0xff),
    STX_zpg, 0x00,
    LDX_imm, ((a >> 8) & 0xff),
    STX_zpg, 0x01,
    LDX_imm, ((a >> 16) & 0xff),
    STX_zpg, 0x02,
    LDX_imm, ((a >> 24) & 0xff),
    STX_zpg, 0x03,
    // b
    LDY_imm, (b & 0xff),
    STY_zpg, 0x04,
    LDY_imm, ((b >> 8) & 0xff),
    STY_zpg, 0x05,
    LDY_imm, ((b >> 16) & 0xff),
    STY_zpg, 0x06,
    LDY_imm, ((b >> 24) & 0xff),
    STY_zpg, 0x07,
    // c: a + b
    LDA_zpg, 0x00,
    ADC_zpg, 0x04,
    STA_zpg, 0x08,
    LDA_zpg, 0x01,
    ADC_zpg, 0x05,
    STA_zpg, 0x09,
    LDA_zpg, 0x02,
    ADC_zpg, 0x06,
    STA_zpg, 0x0a,
    LDA_zpg, 0x03,
    ADC_zpg, 0x07,
    STA_zpg, 0x0b,
  };
  uint16_t program_length = sizeof(program) / sizeof(uint8_t);
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, program_length);
  uint16_t end_of_program = vm.PC + program_length;
  while (vm.PC < end_of_program) {
    VM__step(&vm);
  }
  uint32_t d = (vm.mem[8]) + (vm.mem[9] << 8) + (vm.mem[10] << 16) + (vm.mem[11] << 24);
  assert(c == d);
}
