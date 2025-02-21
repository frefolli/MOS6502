#include <vm/JSR_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__JSR_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  vm->stack[vm->SP++] = (vm->PC & 0xff);
  vm->stack[vm->SP++] = ((vm->PC >> 8) & 0xff);
  vm->PC = addr;
}
