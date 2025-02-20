#include <assert.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t program[] = {
    // idx
    LDA_imm, 0x0a,
    STA_zpg, 0x00,
    
    // n-2, n-1
    LDA_imm, 0x01,
    STA_zpg, 0x01,
    STA_zpg, 0x02,

    // decr idx
    LDA_zpg, 0x00,
    BEQ_rel, 0x0e,
    DEC_zpg, 0x00,

    // load n-2
    LDA_zpg, 0x01,
    // add n-1
    ADC_zpg, 0x02,
    // save n-1 to n-2
    LDX_zpg, 0x02,
    STX_zpg, 0x01,
    // save n
    STA_zpg, 0x02,

    // cycle via idx
    LDA_zpg, 0x00,
    BNE_rel, -0x10,
    LDA_zpg, 0x02,
  };
  uint16_t program_length = sizeof(program) / sizeof(uint8_t);
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, program_length);
  uint16_t end_of_program = vm.PC + program_length;
  while (vm.PC < end_of_program) {
    VM__step(&vm);
  }
  assert(vm.A == 144);
}
