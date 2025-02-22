#include <vm/CLC_impl.h>
#include <vm/macros.h>

void VM__CLC_impl(struct VM* vm) {
  vm->SR.C = 0;
}
