#include <vm/PHA_impl.h>
#include <vm/macros.h>

void VM__PHA_impl(struct VM* vm) {
  VM__push_byte_to_stack(vm, vm->A);
}
