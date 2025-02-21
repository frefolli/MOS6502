#include <vm/ORA_imm.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__ORA_imm(struct VM* vm) {
  uint8_t value = VM__address__imm(vm);
  uint8_t res = vm->A | value;
  VM__setNZ(vm, res);
  vm->A = res;
}
