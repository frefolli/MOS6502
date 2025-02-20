#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vm.h>

void execute_program(struct VM* vm, uint8_t* program, uint16_t program_length) {
  VM__clear(vm);
  VM__reset(vm);
  memcpy(vm->mem, program, program_length);
  printf("Pre-execution\n");
  VM__dump(vm);
  while (vm->PC < program_length) {
    VM__step(vm);
  }
  printf("Post-execution\n");
  VM__dump(vm);
}

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t program[] = {
    ADC_imm, 0x17,
    AND_imm, 0x27
  };
  execute_program(&vm, program, sizeof(program) / sizeof(uint8_t));
}
