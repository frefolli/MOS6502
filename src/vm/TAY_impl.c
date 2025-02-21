#include <vm/TAY_impl.h>
#include <vm/macros.h>

void VM__TAY_impl(struct VM* vm) {
  VM__setNZ(vm, vm->A);
  vm->Y = vm->A;
}
