#include <vm/LDX_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDX_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->X = value;
}
