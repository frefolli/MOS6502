#include <vm/TYA_impl.h>
#include <vm/macros.h>

void VM__TYA_impl(struct VM* vm) {
  VM__setNZ(vm, vm->Y);
  vm->A = vm->Y;
}
