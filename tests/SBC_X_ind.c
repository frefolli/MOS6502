#include <vm/vm.h>
#include <vm/opcodes.h>

int main(void) {
  uint8_t program[] = {SBC_X_ind};
  struct VM vm;
  VM__clear(&vm);
  VM__reset(&vm);
  VM__load(&vm, program, sizeof(program) / sizeof(uint8_t));
  VM__step(&vm);
}
