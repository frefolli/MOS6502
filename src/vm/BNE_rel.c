#include <vm/BNE_rel.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__BNE_rel(struct VM* vm) {
  uint16_t addr = VM__address__rel(vm);
  if (!vm->SR.Z) {
    vm->PC = addr;
  }
}
