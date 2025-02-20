#include <vm/DEC_zpg_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__DEC_zpg_X(struct VM* vm) {
  uint16_t addr = VM__address__zpg_X(vm);
  uint8_t res = vm->mem[addr] - 1;
  VM__setNZ(vm, res);
  vm->mem[addr] = res;
}
