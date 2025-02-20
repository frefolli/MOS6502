#include <vm/STA_abs_Y.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STA_abs_Y(struct VM* vm) {
  uint16_t addr = VM__address__abs_Y(vm);
  vm->mem[addr] = vm->A;
}
