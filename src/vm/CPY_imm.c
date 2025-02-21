#include <vm/CPY_imm.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__CPY_imm(struct VM* vm) {
  uint8_t value = VM__address__imm(vm);
  uint16_t res = vm->Y - (uint16_t)value;
  vm->SR.C = (res >> 8) % 2;
  vm->SR.V = (vm->SR.C == 1);
  VM__setNZ(vm, res);
}
