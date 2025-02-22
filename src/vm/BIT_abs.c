#include <vm/BIT_abs.h>
#include <vm/macros.h>
#include <vm/addressing.h>
#include <stdbool.h>

void VM__BIT_abs(struct VM* vm) {
  uint16_t addr = VM__address__abs(vm);
  uint8_t value = vm->mem[addr];
  bool bit_6 = (value >> 6) % 2;
  bool bit_7 = (value >> 7) % 2;
  vm->SR.N = bit_7;
  vm->SR.V = bit_6;
  vm->SR.Z = ((vm->A & value) == 0);
}
