#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <vm.h>

void execute_program(struct VM* vm, uint8_t* program, uint16_t program_length) {
  VM__clear(vm);
  VM__dump(vm);
  VM__reset(vm);
  VM__dump(vm);
  VM__load(vm, program, program_length);
  printf("Pre-execution\n");
  VM__dump_zeropage(vm);
  VM__dump(vm);
  uint16_t end_of_program = vm->PC + program_length;
  while (vm->PC < end_of_program) {
    VM__step(vm);
  }
  printf("Post-execution\n");
  VM__dump_zeropage(vm);
  VM__dump(vm);
}

bool write_file(const char* filepath, const uint8_t* program, uint16_t program_length) {
  if (program == NULL)
    return false;
  
  FILE* file = fopen(filepath, "w");
  if (file == NULL)
    return false;

  (void)fwrite(program, sizeof(uint8_t), program_length, file);
  fclose(file);
  return true;
}

bool read_file(const char* filepath, uint8_t** program, uint16_t* program_length) {
  if (program == NULL)
    return false;
  if (program_length == NULL)
    return false;

  FILE* file = fopen(filepath, "r");
  if (file == NULL)
    return false;

  fseek(file, 0, SEEK_END);
  uint32_t fsize = ftell(file);
  fseek(file, 0, SEEK_SET);

  if (fsize > 0x10000) {
    fsize = 0x10000;
  }

  *program = malloc(sizeof(uint8_t) * (*program_length));

  if (*program == NULL) {
    fclose(file);
    return false;
  }
  
  *program_length = fsize;
  (void)fread(*program, fsize, 1, file);
  fclose(file);

  return true;
}

int main(int argc, char **argv) {
  struct VM vm;
  uint8_t default_program[] = {
    // idx
    LDA_imm, 0x0a,
    STA_zpg, 0x00,
    
    // n-2, n-1
    LDA_imm, 0x01,
    STA_zpg, 0x01,
    STA_zpg, 0x02,

    // decr idx
    LDA_zpg, 0x00,
    BEQ_rel, 0x0e,
    DEC_zpg, 0x00,

    // load n-2
    LDA_zpg, 0x01,
    // add n-1
    ADC_zpg, 0x02,
    // save n-1 to n-2
    LDX_zpg, 0x02,
    STX_zpg, 0x01,
    // save n
    STA_zpg, 0x02,

    // cycle via idx
    LDA_zpg, 0x00,
    BNE_rel, -0x10,
    LDA_zpg, 0x02,
  };

  if (argc > 1) {
    if (strcmp("-e", argv[1]) == 0) {
      const char* input_file = "program.o65";
      if (argc > 2) {
        input_file = argv[2];
      }
      uint8_t* program = NULL;
      uint16_t program_length = 0;
      assert(read_file(input_file, &program, &program_length));
      execute_program(&vm, program, program_length);
    } else if (strcmp("-o", argv[1]) == 0) {
      const char* output_file = "program.o65";
      if (argc > 2) {
        output_file = argv[2];
      }
      assert(write_file(output_file, default_program, sizeof(default_program) / sizeof(uint8_t)));
    }
  }
}
