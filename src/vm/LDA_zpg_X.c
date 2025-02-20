#include <vm/LDA_zpg_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDA_zpg_X(struct VM* vm) {
  uint16_t addr = VM__address__zpg_X(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->A = value;
}
