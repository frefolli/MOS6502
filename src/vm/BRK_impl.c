#include <vm/BRK_impl.h>
#include <vm/macros.h>

void VM__BRK_impl(struct VM* vm) {
  uint16_t addr = vm->PC;
  struct StatusRegister sr = vm->SR;
  sr.B = 1;
  VM__push_word_to_stack(vm, addr);
  VM__push_SR_to_stack(vm, sr);
  vm->PC = vm->IRQ;
}
