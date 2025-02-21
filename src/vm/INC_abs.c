#include <vm/INC_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__INC_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  uint8_t res = vm->mem[addr] + 1;
  VM__setNZ(vm, res);
  vm->mem[addr] = res;
}
