#include <vm/ASL_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__ASL_A(struct VM* vm) {
  vm->SR.C = vm->A >> 7;
  uint8_t res = vm->A << 1;
  VM__setNZ(vm, res);
  vm->A = res;
}
