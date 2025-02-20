#include <vm/STA_abs_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STA_abs_X(struct VM* vm) {
  uint16_t addr = VM__address__abs_X(vm);
  vm->mem[addr] = vm->A;
}
