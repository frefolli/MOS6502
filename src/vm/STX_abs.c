#include <vm/STX_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STX_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  vm->mem[addr] = vm->X;
}
