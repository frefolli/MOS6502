#include <vm/LDA_abs_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDA_abs_X(struct VM* vm) {
  uint16_t addr = VM__address__abs_X(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->A = value;
}
