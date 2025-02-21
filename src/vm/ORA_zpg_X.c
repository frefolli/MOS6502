#include <vm/ORA_zpg_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__ORA_zpg_X(struct VM* vm) {
  uint16_t addr = VM__address__zpg_X(vm);
  uint8_t value = vm->mem[addr];
  uint8_t res = vm->A | value;
  VM__setNZ(vm, res);
  vm->A = res;
}
