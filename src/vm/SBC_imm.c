#include <vm/SBC_imm.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__SBC_imm(struct VM* vm) {
  uint8_t value = VM__address__imm(vm) + !vm->SR.C;
  uint8_t res = vm->A - value;
  vm->SR.C = (vm->A >= value);
  vm->SR.V = (vm->A < res);
  VM__setNZ(vm, res);
  vm->A = res;
}
