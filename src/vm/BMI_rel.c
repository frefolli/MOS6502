#include <vm/BMI_rel.h>
#include <vm/macros.h>
#include <vm/addressing.h>

void VM__BMI_rel(struct VM* vm) {
  uint16_t addr = VM__address__rel(vm);
  if (vm->SR.N) {
    vm->PC = addr;
  }
}
