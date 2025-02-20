#include <vm/LDA_X_ind.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDA_X_ind(struct VM* vm) {
  uint16_t addr = VM__address__X_ind(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->A = value;
}
