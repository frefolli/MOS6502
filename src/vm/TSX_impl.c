#include <vm/TSX_impl.h>
#include <vm/macros.h>

void VM__TSX_impl(struct VM* vm) {
  VM__setNZ(vm, vm->SP);
  vm->X = vm->SP;
}
