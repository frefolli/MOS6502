#include <vm/EOR_X_ind.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__EOR_X_ind(struct VM* vm) {
  uint16_t addr = VM__address__X_ind(vm);
  uint8_t value = vm->mem[addr];
  uint8_t res = vm->A ^ value;
  VM__setNZ(vm, res);
  vm->A = res;
}
