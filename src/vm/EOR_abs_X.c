#include <vm/EOR_abs_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__EOR_abs_X(struct VM* vm) {
  uint16_t addr = VM__address__abs_X(vm);
  uint8_t value = vm->mem[addr];
  uint8_t res = vm->A ^ value;
  VM__setNZ(vm, res);
  vm->A = res;
}
