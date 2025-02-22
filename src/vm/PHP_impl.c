#include <vm/PHP_impl.h>
#include <vm/macros.h>

void VM__PHP_impl(struct VM* vm) {
  struct StatusRegister sr = vm->SR;
  sr.B = 1;
  sr.I = 1;
  VM__push_SR_to_stack(vm, sr);
}
