#include <vm/TXS_impl.h>
#include <vm/macros.h>

void VM__TXS_impl(struct VM* vm) {
  VM__setNZ(vm, vm->X);
  vm->SP = vm->X;
}
