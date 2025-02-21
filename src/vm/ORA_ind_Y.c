#include <vm/ORA_ind_Y.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__ORA_ind_Y(struct VM* vm) {
  uint16_t addr = VM__address__ind_Y(vm);
  uint8_t value = vm->mem[addr];
  uint8_t res = vm->A | value;
  VM__setNZ(vm, res);
  vm->A = res;
}
