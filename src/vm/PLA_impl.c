#include <vm/PLA_impl.h>
#include <vm/macros.h>

void VM__PLA_impl(struct VM* vm) {
  vm->A = VM__pull_byte_from_stack(vm);
}
