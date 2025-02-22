#include <vm/DEY_impl.h>
#include <vm/macros.h>

void VM__DEY_impl(struct VM* vm) {
  uint8_t res = vm->Y - 1;
  VM__setNZ(vm, res);
  vm->Y = res;
}
