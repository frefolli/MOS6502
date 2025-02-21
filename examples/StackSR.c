#include <assert.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t program[] = {
    // idx
    LDA_imm, 0xf1,
    PHP_impl,
    LDA_imm, 0x02,
    PLP_impl,
  };
  uint16_t program_length = sizeof(program) / sizeof(uint8_t);
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, program_length);
  uint16_t end_of_program = vm.PC + program_length;
  assert(vm.SR.N == 0);
  while (vm.PC < end_of_program) {
    VM__step(&vm);
  }
  assert(vm.SR.N == 1);
}
