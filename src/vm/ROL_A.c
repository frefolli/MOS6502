#include <vm/ROL_A.h>
#include <vm/macros.h>

void VM__ROL_A(struct VM* vm) {
  vm->SR.C = (vm->A >> 7) % 2;
  uint8_t res = vm->SR.C + (vm->A << 1);
  VM__setNZ(vm, res);
  vm->A = res;
}
