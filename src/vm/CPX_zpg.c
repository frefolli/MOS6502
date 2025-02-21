#include <vm/CPX_zpg.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__CPX_zpg(struct VM* vm) {
  uint16_t addr = VM__address__zpg(vm);
  uint8_t value = vm->mem[addr];
  uint16_t res = vm->X - (uint16_t)value;
  vm->SR.C = (res >> 8) % 2;
  vm->SR.V = (vm->SR.C == 1);
  VM__setNZ(vm, res);
}
