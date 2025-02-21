#include <vm/BRK_impl.h>
#include <vm/macros.h>

void VM__BRK_impl(struct VM* vm) {
  uint16_t addr = vm->PC + 1;
  vm->stack[vm->SP++] = (addr & 0xff);
  vm->stack[vm->SP++] = ((addr >> 8) & 0xff);
  vm->stack[vm->SP++] = *((uint8_t*)&vm->SR);
  struct StatusRegister* sr = (struct StatusRegister*)(vm->stack + vm->SP - 1);
  sr->B = 1;
  vm->PC = vm->IRQ;
}
