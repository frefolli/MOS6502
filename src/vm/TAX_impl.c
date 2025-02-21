#include <vm/TAX_impl.h>
#include <vm/macros.h>

void VM__TAX_impl(struct VM* vm) {
  VM__setNZ(vm, vm->A);
  vm->X = vm->A;
}
