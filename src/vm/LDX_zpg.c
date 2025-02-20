#include <vm/LDX_zpg.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDX_zpg(struct VM* vm) {
  uint16_t addr = VM__address__zpg(vm);
  uint8_t value = vm->mem[addr];
  VM__setNZ(vm, value);
  vm->X = value;
}
