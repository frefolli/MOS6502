#include <vm/ROR_A.h>
#include <vm/macros.h>

void VM__ROR_A(struct VM* vm) {
  vm->SR.C = vm->A % 2;
  uint8_t res = (vm->SR.C << 7) + (vm->A >> 1);
  VM__setNZ(vm, res);
  vm->A = res;
}
