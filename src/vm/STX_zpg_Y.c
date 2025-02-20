#include <vm/STX_zpg_Y.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STX_zpg_Y(struct VM* vm) {
  uint16_t addr = VM__address__zpg_Y(vm);
  vm->mem[addr] = vm->X;
}
