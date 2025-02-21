#include <vm/PLA_impl.h>
#include <vm/macros.h>

void VM__PLA_impl(struct VM* vm) {
  vm->A = vm->stack[--vm->SP];
}
