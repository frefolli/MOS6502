#include <vm/vm.h>
#include <vm/opcodes.h>

int main(void) {
  struct VM vm;
  VM__clear(&vm);
  VM__reset(&vm);
  vm.mem[0] = CLV_impl;
  vm.mem[1] = 0x00;
  VM__step(&vm);
}
