#include <vm/RTS_impl.h>
#include <vm/macros.h>

void VM__RTS_impl(struct VM* vm) {
  vm->PC = VM__pull_word_from_stack(vm);
}
