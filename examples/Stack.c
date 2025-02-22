#include <assert.h>
#include <vm.h>

int main(int argc, char **argv) {
  struct VM vm;
  VM__clear(&vm);
  VM__reset(&vm);
  VM__push_byte_to_stack(&vm, 0x12);
  VM__push_word_to_stack(&vm, 0x2345);
  assert(VM__pull_word_from_stack(&vm) == 0x2345);
  assert(VM__pull_byte_from_stack(&vm) == 0x12);
}
