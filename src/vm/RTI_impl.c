#include <vm/RTI_impl.h>
#include <vm/macros.h>
#include <stdbool.h>

void VM__RTI_impl(struct VM* vm) {
  bool bit_B = vm->SR.B;
  bool bit_I = vm->SR.I;
  vm->SR = VM__pull_SR_from_stack(vm);
  vm->SR.B = bit_B;
  vm->SR.I = bit_I;
  vm->PC = VM__pull_word_from_stack(vm);
}
