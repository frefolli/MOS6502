#include <vm/STY_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__STY_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  vm->mem[addr] = vm->Y;
}
