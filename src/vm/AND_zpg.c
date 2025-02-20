#include <vm/AND_zpg.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__AND_zpg(struct VM* vm) {
  uint16_t addr = VM__address__zpg(vm);
  uint8_t value = vm->mem[addr];
  uint8_t res = vm->A & value;
  VM__setNZ(vm, res);
  vm->A = res;
}
