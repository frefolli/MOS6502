#include <vm/DEX_impl.h>
#include <vm/macros.h>

void VM__DEX_impl(struct VM* vm) {
  uint8_t res = vm->X - 1;
  VM__setNZ(vm, res);
  vm->X = res;
}
