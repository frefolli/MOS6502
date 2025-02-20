#include <vm/DEC_abs_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__DEC_abs_X(struct VM* vm) {
  uint16_t addr = VM__address__abs_X(vm);
  uint8_t res = vm->mem[addr] - 1;
  VM__setNZ(vm, res);
  vm->mem[addr] = res;
}
