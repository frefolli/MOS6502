#include <vm/JMP_ind.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__JMP_ind(struct VM* vm) {
  uint16_t addr = VM__address__ind(vm);
  vm->PC = addr;
}
