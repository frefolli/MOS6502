#ifndef VM_VM_H
#define VM_VM_H
#include <stdint.h>

struct VM {
  uint8_t mem[64 * 1024];
  uint8_t stack[256];
  uint16_t PC;
  uint8_t A;
  uint8_t X;
  uint8_t Y;
  struct StatusRegister {
    uint8_t N : 1; // Negative
    uint8_t V : 1; // Overflow
    uint8_t _ : 1; // Ignored
    uint8_t B : 1; // Break
    uint8_t D : 1; // Decimal
    uint8_t I : 1; // Interrupt
    uint8_t Z : 1; // Zero
    uint8_t C : 1; // Carry
  } SR;
  uint8_t SP;
  uint16_t NMI;
  uint16_t RES;
  uint16_t IRQ;
};

void VM__clear(struct VM* vm);
void VM__reset(struct VM* vm);
void VM__load(struct VM* vm, uint8_t* program, uint16_t program_length);
void VM__step(struct VM* vm);
void VM__dump(struct VM* vm);
void VM__dump_mem(struct VM* vm);
void VM__dump_stack(struct VM* vm);
void VM__dump_zeropage(struct VM* vm);
uint8_t VM__read_next_opcode_from_mem(struct VM* vm);
uint16_t VM__read_next_immediate_from_mem(struct VM* vm);
uint16_t VM__read_next_address_from_mem(struct VM* vm);
uint16_t VM__read_address_from_mem(struct VM* vm, uint16_t addr);
void VM__setNZ(struct VM* vm, uint8_t value);
#endif//VM_H
