#include <vm/BVC_rel.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__BVC_rel(struct VM* vm) {
  uint16_t addr = VM__address__rel(vm);
  if (!vm->SR.V) {
    vm->PC = addr;
  }
}
