#include <vm/JMP_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__JMP_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  vm->PC = addr;
}
