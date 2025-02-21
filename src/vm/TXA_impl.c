#include <vm/TXA_impl.h>
#include <vm/macros.h>

void VM__TXA_impl(struct VM* vm) {
  VM__setNZ(vm, vm->X);
  vm->A = vm->X;
}
