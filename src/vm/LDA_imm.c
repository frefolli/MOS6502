#include <vm/LDA_imm.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__LDA_imm(struct VM* vm) {
  uint8_t value = VM__address__imm(vm);
  VM__setNZ(vm, value);
  vm->A = value;
}
