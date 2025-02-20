#include <vm/vm.h>
#include <vm/instructions.h>
#include <vm/opcodes.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void VM__clear(struct VM* vm) {
  if (vm == NULL)
    return;
  memset(vm, 0, sizeof(struct VM));
}

void VM__reset(struct VM* vm) {
  if (vm == NULL)
    return;
  vm->PC = vm->RES;
}

void VM__step(struct VM* vm) {
  if (vm == NULL)
    return;
  uint8_t opcode = VM__read_next_opcode_from_mem(vm);

  switch (opcode) {
    case BRK_impl: VM__BRK_impl(vm); break;
    case ORA_X_ind: VM__ORA_X_ind(vm); break;
    case ORA_zpg: VM__ORA_zpg(vm); break;
    case ASL_zpg: VM__ASL_zpg(vm); break;
    case PHP_impl: VM__PHP_impl(vm); break;
    case ORA_imm: VM__ORA_imm(vm); break;
    case ASL_A: VM__ASL_A(vm); break;
    case ORA_abs: VM__ORA_abs(vm); break;
    case ASL_abs: VM__ASL_abs(vm); break;
    case BPL_rel: VM__BPL_rel(vm); break;
    case ORA_ind_Y: VM__ORA_ind_Y(vm); break;
    case ORA_zpg_X: VM__ORA_zpg_X(vm); break;
    case ASL_zpg_X: VM__ASL_zpg_X(vm); break;
    case CLC_impl: VM__CLC_impl(vm); break;
    case ORA_abs_Y: VM__ORA_abs_Y(vm); break;
    case ORA_abs_X: VM__ORA_abs_X(vm); break;
    case ASL_abs_X: VM__ASL_abs_X(vm); break;
    case JSR_abs: VM__JSR_abs(vm); break;
    case AND_X_ind: VM__AND_X_ind(vm); break;
    case BIT_zpg: VM__BIT_zpg(vm); break;
    case AND_zpg: VM__AND_zpg(vm); break;
    case ROL_zpg: VM__ROL_zpg(vm); break;
    case PLP_impl: VM__PLP_impl(vm); break;
    case AND_imm: VM__AND_imm(vm); break;
    case ROL_A: VM__ROL_A(vm); break;
    case BIT_abs: VM__BIT_abs(vm); break;
    case AND_abs: VM__AND_abs(vm); break;
    case ROL_abs: VM__ROL_abs(vm); break;
    case BMI_rel: VM__BMI_rel(vm); break;
    case AND_ind_Y: VM__AND_ind_Y(vm); break;
    case AND_zpg_X: VM__AND_zpg_X(vm); break;
    case ROL_zpg_X: VM__ROL_zpg_X(vm); break;
    case SEC_impl: VM__SEC_impl(vm); break;
    case AND_abs_Y: VM__AND_abs_Y(vm); break;
    case AND_abs_X: VM__AND_abs_X(vm); break;
    case ROL_abs_X: VM__ROL_abs_X(vm); break;
    case RTI_impl: VM__RTI_impl(vm); break;
    case EOR_X_ind: VM__EOR_X_ind(vm); break;
    case EOR_zpg: VM__EOR_zpg(vm); break;
    case LSR_zpg: VM__LSR_zpg(vm); break;
    case PHA_impl: VM__PHA_impl(vm); break;
    case EOR_imm: VM__EOR_imm(vm); break;
    case LSR_A: VM__LSR_A(vm); break;
    case JMP_abs: VM__JMP_abs(vm); break;
    case EOR_abs: VM__EOR_abs(vm); break;
    case LSR_abs: VM__LSR_abs(vm); break;
    case BVC_rel: VM__BVC_rel(vm); break;
    case EOR_ind_Y: VM__EOR_ind_Y(vm); break;
    case EOR_zpg_X: VM__EOR_zpg_X(vm); break;
    case LSR_zpg_X: VM__LSR_zpg_X(vm); break;
    case CLI_impl: VM__CLI_impl(vm); break;
    case EOR_abs_Y: VM__EOR_abs_Y(vm); break;
    case EOR_abs_X: VM__EOR_abs_X(vm); break;
    case LSR_abs_X: VM__LSR_abs_X(vm); break;
    case RTS_impl: VM__RTS_impl(vm); break;
    case ADC_X_ind: VM__ADC_X_ind(vm); break;
    case ADC_zpg: VM__ADC_zpg(vm); break;
    case ROR_zpg: VM__ROR_zpg(vm); break;
    case PLA_impl: VM__PLA_impl(vm); break;
    case ADC_imm: VM__ADC_imm(vm); break;
    case ROR_A: VM__ROR_A(vm); break;
    case JMP_ind: VM__JMP_ind(vm); break;
    case ADC_abs: VM__ADC_abs(vm); break;
    case ROR_abs: VM__ROR_abs(vm); break;
    case BVS_rel: VM__BVS_rel(vm); break;
    case ADC_ind_Y: VM__ADC_ind_Y(vm); break;
    case ADC_zpg_X: VM__ADC_zpg_X(vm); break;
    case ROR_zpg_X: VM__ROR_zpg_X(vm); break;
    case SEI_impl: VM__SEI_impl(vm); break;
    case ADC_abs_Y: VM__ADC_abs_Y(vm); break;
    case ADC_abs_X: VM__ADC_abs_X(vm); break;
    case ROR_abs_X: VM__ROR_abs_X(vm); break;
    case STA_X_ind: VM__STA_X_ind(vm); break;
    case STY_zpg: VM__STY_zpg(vm); break;
    case STA_zpg: VM__STA_zpg(vm); break;
    case STX_zpg: VM__STX_zpg(vm); break;
    case DEY_impl: VM__DEY_impl(vm); break;
    case TXA_impl: VM__TXA_impl(vm); break;
    case STY_abs: VM__STY_abs(vm); break;
    case STA_abs: VM__STA_abs(vm); break;
    case STX_abs: VM__STX_abs(vm); break;
    case BCC_rel: VM__BCC_rel(vm); break;
    case STA_ind_Y: VM__STA_ind_Y(vm); break;
    case STY_zpg_X: VM__STY_zpg_X(vm); break;
    case STA_zpg_X: VM__STA_zpg_X(vm); break;
    case STX_zpg_Y: VM__STX_zpg_Y(vm); break;
    case TYA_impl: VM__TYA_impl(vm); break;
    case STA_abs_Y: VM__STA_abs_Y(vm); break;
    case TXS_impl: VM__TXS_impl(vm); break;
    case STA_abs_X: VM__STA_abs_X(vm); break;
    case LDY_imm: VM__LDY_imm(vm); break;
    case LDA_X_ind: VM__LDA_X_ind(vm); break;
    case LDX_imm: VM__LDX_imm(vm); break;
    case LDY_zpg: VM__LDY_zpg(vm); break;
    case LDA_zpg: VM__LDA_zpg(vm); break;
    case LDX_zpg: VM__LDX_zpg(vm); break;
    case TAY_impl: VM__TAY_impl(vm); break;
    case LDA_imm: VM__LDA_imm(vm); break;
    case TAX_impl: VM__TAX_impl(vm); break;
    case LDY_abs: VM__LDY_abs(vm); break;
    case LDA_abs: VM__LDA_abs(vm); break;
    case LDX_abs: VM__LDX_abs(vm); break;
    case BCS_rel: VM__BCS_rel(vm); break;
    case LDA_ind_Y: VM__LDA_ind_Y(vm); break;
    case LDY_zpg_X: VM__LDY_zpg_X(vm); break;
    case LDA_zpg_X: VM__LDA_zpg_X(vm); break;
    case LDX_zpg_Y: VM__LDX_zpg_Y(vm); break;
    case CLV_impl: VM__CLV_impl(vm); break;
    case LDA_abs_Y: VM__LDA_abs_Y(vm); break;
    case TSX_impl: VM__TSX_impl(vm); break;
    case LDY_abs_X: VM__LDY_abs_X(vm); break;
    case LDA_abs_X: VM__LDA_abs_X(vm); break;
    case LDX_abs_Y: VM__LDX_abs_Y(vm); break;
    case CPY_imm: VM__CPY_imm(vm); break;
    case CMP_X_ind: VM__CMP_X_ind(vm); break;
    case CPY_zpg: VM__CPY_zpg(vm); break;
    case CMP_zpg: VM__CMP_zpg(vm); break;
    case DEC_zpg: VM__DEC_zpg(vm); break;
    case INY_impl: VM__INY_impl(vm); break;
    case CMP_imm: VM__CMP_imm(vm); break;
    case DEX_impl: VM__DEX_impl(vm); break;
    case CPY_abs: VM__CPY_abs(vm); break;
    case CMP_abs: VM__CMP_abs(vm); break;
    case DEC_abs: VM__DEC_abs(vm); break;
    case BNE_rel: VM__BNE_rel(vm); break;
    case CMP_ind_Y: VM__CMP_ind_Y(vm); break;
    case CMP_zpg_X: VM__CMP_zpg_X(vm); break;
    case DEC_zpg_X: VM__DEC_zpg_X(vm); break;
    case CLD_impl: VM__CLD_impl(vm); break;
    case CMP_abs_Y: VM__CMP_abs_Y(vm); break;
    case CMP_abs_X: VM__CMP_abs_X(vm); break;
    case DEC_abs_X: VM__DEC_abs_X(vm); break;
    case CPX_imm: VM__CPX_imm(vm); break;
    case SBC_X_ind: VM__SBC_X_ind(vm); break;
    case CPX_zpg: VM__CPX_zpg(vm); break;
    case SBC_zpg: VM__SBC_zpg(vm); break;
    case INC_zpg: VM__INC_zpg(vm); break;
    case INX_impl: VM__INX_impl(vm); break;
    case SBC_imm: VM__SBC_imm(vm); break;
    case NOP_impl: VM__NOP_impl(vm); break;
    case CPX_abs: VM__CPX_abs(vm); break;
    case SBC_abs: VM__SBC_abs(vm); break;
    case INC_abs: VM__INC_abs(vm); break;
    case BEQ_rel: VM__BEQ_rel(vm); break;
    case SBC_ind_Y: VM__SBC_ind_Y(vm); break;
    case SBC_zpg_X: VM__SBC_zpg_X(vm); break;
    case INC_zpg_X: VM__INC_zpg_X(vm); break;
    case SED_impl: VM__SED_impl(vm); break;
    case SBC_abs_Y: VM__SBC_abs_Y(vm); break;
    case SBC_abs_X: VM__SBC_abs_X(vm); break;
    case INC_abs_X: VM__INC_abs_X(vm); break;
    default: assert(false);
  }
}

void VM__dump(struct VM* vm) {
  printf("PC IRQ SR AC XR YR SP\n");
  printf("%2x  %2x %2x %2x %2x %2x %2x\n",
         vm->PC, vm->IRQ,
         vm->SR, vm->A,
         vm->X, vm->Y,
         vm->SP);
}

void VM__setNZ(struct VM* vm, uint8_t value) {
  vm->SR.N = (value >> 7) % 2;
  vm->SR.Z = (value == 0);
}

uint8_t VM__read_next_opcode_from_mem(struct VM* vm) {
  return vm->mem[vm->PC++];
}

uint16_t VM__read_next_immediate_from_mem(struct VM* vm) {
  uint16_t value = 0;
  value = vm->mem[vm->PC++];
  return value;
}

uint16_t VM__read_next_address_from_mem(struct VM* vm) {
  uint16_t value = 0;
  value = vm->mem[vm->PC++];
  value += (vm->mem[vm->PC++] << 8);
  return value;
}

uint16_t VM__read_address_from_mem(struct VM* vm, uint16_t addr) {
  uint16_t value = 0;
  value = vm->mem[addr];
  value += (vm->mem[addr + 1] << 8);
  return value;
}
