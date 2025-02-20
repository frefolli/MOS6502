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
  VM__dump_zeropage(vm);
  VM__dump(vm);
  uint16_t end_of_program = vm->PC + program_length;
  while (vm->PC < end_of_program) {
    VM__step(vm);
  }
  printf("Post-execution\n");
  VM__dump_zeropage(vm);
  VM__dump(vm);
}

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t program[] = {
    // idx
    LDA_imm, 0x17,
    STA_zpg, 0x00,
    STA_zpg, 0x01,
    STA_zpg, 0x02,
    STA_zpg, 0x03,
    STA_zpg, 0x04
  };
  execute_program(&vm, program, sizeof(program) / sizeof(uint8_t));
}
