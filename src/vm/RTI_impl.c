#include <vm/RTI_impl.h>
#include <vm/macros.h>
#include <stdbool.h>

void VM__RTI_impl(struct VM* vm) {
  bool bit_B = vm->SR.B;
  bool bit_I = vm->SR.I;
  vm->SR = *((struct StatusRegister*)(vm->stack + vm->SP - 1));
  vm->SR.B = bit_B;
  vm->SR.I = bit_I;
  vm->SP--;
  uint16_t addr = vm->stack[vm->SP - 2] + (vm->stack[vm->SP - 1] << 8);
  vm->SP -= 2;
  vm->PC = addr;
}
