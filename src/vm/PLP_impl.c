#include <vm/PLP_impl.h>
#include <vm/macros.h>

void VM__PLP_impl(struct VM* vm) {
  *((uint8_t*) &vm->SR) = vm->stack[--vm->SP];
}
