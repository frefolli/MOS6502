#include <assert.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t a = 0x12, b = 0x2f;
  uint8_t c = a + b;
  uint8_t program[] = {
    // Setup zpg
    // a: 0x12
    LDX_imm, a,
    STX_zpg, 0x00,
    // b: 0x2f
    LDY_imm, b,
    STY_zpg, 0x01,
    // c: a + b
    LDA_zpg, 0x00,
    ADC_zpg, 0x01,
    STA_zpg, 0x02
  };
  uint16_t program_length = sizeof(program) / sizeof(uint8_t);
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, program_length);
  uint16_t end_of_program = vm.PC + program_length;
  while (vm.PC < end_of_program) {
    VM__step(&vm);
  }
  uint8_t d = vm.mem[2];
  assert(c == d);
}
