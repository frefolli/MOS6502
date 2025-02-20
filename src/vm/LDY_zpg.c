#include <vm/LDY_zpg.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDY_zpg(struct VM* vm) {
  uint16_t addr = VM__address__zpg(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->Y = value;
}
