#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vm.h>

void execute_program(struct VM* vm, uint8_t* program, uint16_t program_length) {
  VM__clear(vm);
  VM__dump(vm);
  VM__reset(vm);
  VM__dump(vm);
  VM__load(vm, program, program_length);
  printf("Pre-execution\n");
  VM__dump_mem(vm);
  VM__dump(vm);
  uint16_t end_of_program = vm->PC + program_length;
  while (vm->PC < end_of_program) {
    VM__step(vm);
  }
  printf("Post-execution\n");
  VM__dump_mem(vm);
  VM__dump(vm);
}

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t program[] = {
    // idx
    LDA_imm, 0x05,
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
  execute_program(&vm, program, sizeof(program) / sizeof(uint8_t));
}
