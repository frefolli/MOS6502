#include <vm/ROR_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__ROR_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  vm->SR.C = vm->mem[addr] % 2;
  uint8_t res = (vm->SR.C << 7) + (vm->mem[addr] >> 1);
  VM__setNZ(vm, res);
  vm->mem[addr] = res;
}
