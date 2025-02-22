#include <vm/LSR_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LSR_A(struct VM* vm) {
  vm->SR.C = vm->A % 2;
  uint8_t res = vm->A >> 1;
  VM__setNZ(vm, res);
  vm->A = res;
}
