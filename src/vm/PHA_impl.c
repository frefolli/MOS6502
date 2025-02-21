#include <vm/PHA_impl.h>
#include <vm/macros.h>

void VM__PHA_impl(struct VM* vm) {
  vm->stack[vm->SP++] = vm->A;
}
