#include <vm/CMP_X_ind.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__CMP_X_ind(struct VM* vm) {
  uint16_t addr = VM__address__X_ind(vm);
  uint8_t value = vm->mem[addr];
  uint16_t res = vm->A - (uint16_t)value;
  vm->SR.C = (res >> 8) % 2;
  vm->SR.V = (vm->SR.C == 1);
  VM__setNZ(vm, res);
}
