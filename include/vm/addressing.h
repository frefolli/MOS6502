#ifndef VM_ADDRESSING_H
#define VM_ADDRESSING_H
#include <vm/vm.h>

/* Returns the immediate value */
uint8_t VM__address__imm(struct VM* vm);

/* Returns the address */
uint16_t VM__address__abs(struct VM* vm);
uint16_t VM__address__abs_X(struct VM* vm);
uint16_t VM__address__abs_Y(struct VM* vm);
uint16_t VM__address__zpg(struct VM* vm);
uint16_t VM__address__zpg_X(struct VM* vm);
uint16_t VM__address__zpg_Y(struct VM* vm);
uint16_t VM__address__ind(struct VM* vm);
uint16_t VM__address__X_ind(struct VM* vm);
uint16_t VM__address__ind_Y(struct VM* vm);
uint16_t VM__address__rel(struct VM* vm);
#endif//VM_ADDRESSING_H
