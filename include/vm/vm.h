#ifndef VM_VM_H
#define VM_VM_H
#include <stdint.h>
#include <stdbool.h>

struct VM {
  uint8_t mem[64 * 1024];
  uint16_t PC;
  uint8_t A;
  uint8_t X;
  uint8_t Y;
  struct StatusRegister {
    uint8_t N : 1; // Negative
    uint8_t V : 1; // Overflow
    uint8_t H : 1; // 6502 Ignored (now Halt bit)
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
  void (*interrupt_handler)(struct VM* vm);
};

enum InterruptType {
  NO_INTERRUPT = 0x00,
  SOFTWARE_INTERRUPT = 0x01,
  HARDWARE_INTERRUPT = 0x02
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
uint8_t VM__pull_byte_from_stack(struct VM* vm);
void VM__push_byte_to_stack(struct VM* vm, uint8_t byte);
uint16_t VM__pull_word_from_stack(struct VM* vm);
void VM__push_word_to_stack(struct VM* vm, uint16_t word);
struct StatusRegister VM__pull_SR_from_stack(struct VM* vm);
void VM__push_SR_to_stack(struct VM* vm, struct StatusRegister SR);
void VM__setNZ(struct VM* vm, uint8_t value);
enum InterruptType VM__detect_interrupt(struct VM*);
void VM__execute(struct VM* vm, uint8_t* program, uint16_t program_length);
#endif//VM_H
