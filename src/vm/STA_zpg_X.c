#include <vm/STA_zpg_X.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STA_zpg_X(struct VM* vm) {
  uint16_t addr = VM__address__zpg_X(vm);
  vm->mem[addr] = vm->A;
}
