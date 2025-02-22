#include <vm/LSR_zpg_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LSR_zpg_X(struct VM* vm) {
  uint16_t addr = VM__address__zpg_X(vm);
  vm->SR.C = vm->mem[addr] % 2;
  uint8_t res = vm->mem[addr] >> 1;
  VM__setNZ(vm, res);
  vm->mem[addr] = res;
}
