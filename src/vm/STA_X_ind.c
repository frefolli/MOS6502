#include <vm/STA_X_ind.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STA_X_ind(struct VM* vm) {
  uint16_t addr = VM__address__X_ind(vm);
  vm->mem[addr] = vm->A;
}
