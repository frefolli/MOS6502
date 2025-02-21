#include <vm/RTS_impl.h>
#include <vm/macros.h>

void VM__RTS_impl(struct VM* vm) {
  uint16_t addr = vm->stack[vm->SP - 2] + (vm->stack[vm->SP - 1] << 8);
  vm->SP -= 2;
  vm->PC = addr;
}
