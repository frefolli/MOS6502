#include <vm/LDA_ind_Y.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDA_ind_Y(struct VM* vm) {
  uint16_t addr = VM__address__ind_Y(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->A = value;
}
