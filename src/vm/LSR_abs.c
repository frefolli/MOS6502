#include <vm/LSR_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LSR_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  vm->SR.C = vm->mem[addr] % 2;
  uint8_t res = vm->mem[addr] >> 1;
  VM__setNZ(vm, res);
  vm->mem[addr] = res;
}
