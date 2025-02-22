#include <vm/INY_impl.h>
#include <vm/macros.h>

void VM__INY_impl(struct VM* vm) {
  uint8_t res = vm->Y + 1;
  VM__setNZ(vm, res);
  vm->Y = res;
}
