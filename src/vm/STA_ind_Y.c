#include <vm/STA_ind_Y.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STA_ind_Y(struct VM* vm) {
  uint16_t addr = VM__address__ind_Y(vm);
  vm->mem[addr] = vm->A;
}
