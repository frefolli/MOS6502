#include <vm/JSR_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__JSR_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  VM__push_word_to_stack(vm, vm->PC);
  vm->PC = addr;
}
