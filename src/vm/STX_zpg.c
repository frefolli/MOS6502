#include <vm/STX_zpg.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STX_zpg(struct VM* vm) {
  uint16_t addr = VM__address__zpg(vm);
  vm->mem[addr] = vm->X;
}
