#include <vm/SBC_zpg_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__SBC_zpg_X(struct VM* vm) {
  uint16_t addr = VM__address__zpg_X(vm);
  uint8_t value = vm->mem[addr] + !vm->SR.C;
  uint8_t res = vm->A - value;
  vm->SR.C = (vm->A >= value);
  vm->SR.V = (vm->A < res);
  VM__setNZ(vm, res);
  vm->A = res;
}
