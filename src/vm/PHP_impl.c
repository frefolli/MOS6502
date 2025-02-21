#include <vm/PHP_impl.h>
#include <vm/macros.h>

void VM__PHP_impl(struct VM* vm) {
  vm->stack[vm->SP++] = *((uint8_t*) &vm->SR);
  struct StatusRegister* sr = (struct StatusRegister*)(vm->stack + vm->SP - 1);
  sr->B = 1;
  sr->I = 1;
}
