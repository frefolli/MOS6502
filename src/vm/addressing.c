#include <vm/addressing.h>
#include <vm/macros.h>

uint8_t VM__address__imm(struct VM* vm) {
  return VM__read_next_immediate_from_mem(vm);
}

uint16_t VM__address__abs(struct VM* vm) {
  return VM__read_next_address_from_mem(vm);
}

uint16_t VM__address__abs_X(struct VM* vm) {
  return VM__read_next_address_from_mem(vm) + vm->X;
}

uint16_t VM__address__abs_Y(struct VM* vm) {
  return VM__read_next_address_from_mem(vm) + vm->Y;
}

uint16_t VM__address__zpg(struct VM* vm) {
  return VM__read_next_immediate_from_mem(vm);
}

uint16_t VM__address__zpg_X(struct VM* vm) {
  return VM__read_next_immediate_from_mem(vm) + vm->X;
}

uint16_t VM__address__zpg_Y(struct VM* vm) {
  return VM__read_next_immediate_from_mem(vm) + vm->Y;
}

uint16_t VM__address__ind(struct VM* vm) {
  uint16_t addr = VM__read_next_address_from_mem(vm);
  return VM__read_address_from_mem(vm, addr);
}

uint16_t VM__address__X_ind(struct VM* vm) {
  uint16_t addr = VM__read_next_immediate_from_mem(vm) + vm->X;
  return VM__read_address_from_mem(vm, addr);
}

uint16_t VM__address__ind_Y(struct VM* vm) {
  uint16_t addr = VM__read_next_immediate_from_mem(vm);
  return VM__read_address_from_mem(vm, addr) + vm->Y;
}

uint16_t VM__address__rel(struct VM* vm) {
  uint16_t addr = VM__read_next_immediate_from_mem(vm);
  return vm->PC + addr;
}
