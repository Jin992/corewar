
#include "../includes/operations.h"

u_int16_t get_2_bytes(t_VM *vm, int pos)
{
    u_int16_t	res;
    u_int8_t	bytes[2];

    bytes[0] = vm->memory[pos % MEM_SIZE];
    bytes[1] = vm->memory[(pos + 1) % MEM_SIZE];
    res = *(u_int16_t*)&bytes[0];
    return  (res = REVERSE_2_BYTES(res));
}

u_int32_t get_4_bytes(t_VM *vm, int pos)
{
    u_int32_t	res;
    u_int8_t	bytes[4];

    bytes[0] = vm->memory[pos % MEM_SIZE];
    bytes[1] = vm->memory[(pos + 1) % MEM_SIZE];
    bytes[2] = vm->memory[(pos + 2) % MEM_SIZE];
    bytes[3] = vm->memory[(pos + 3) % MEM_SIZE];
    res = *(u_int32_t*)&bytes[0];
    return  (res = REVERSE_4_BYTES(res));
}

void	move_pc(t_process *cur, int shift)
{
    cur->pc = (cur->pc + shift) % MEM_SIZE;
}

u_int32_t first_operand(t_VM *vm, t_process *cur, int *shift)
{
    if (IS_REG_S(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        *shift += 1;
        return ((u_int32_t) REVERSE_4_BYTES(*(u_int32_t *) \
        &cur->reg[vm->memory[(cur->pc + 2) % MEM_SIZE]]));
    }
    else if (IS_DIR_S(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        *shift += 4;
        return (get_4_bytes(vm, cur->pc + 2));
    }
    else if (IS_IND_S(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int32_t) get_2_bytes(vm, cur->pc + 2));
    }
    return (0);
}

u_int32_t second_operand(t_VM *vm, t_process *cur, int *shift)
{
    int tmp;

    tmp = *shift + 1;
    if (IS_REG_M(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        *shift += 1;
        return ((u_int32_t) REVERSE_4_BYTES(*(u_int32_t *) \
        &cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE]]));
    }
    else if (IS_DIR_M(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        *shift += 4;
        return (get_4_bytes(vm, cur->pc + tmp));
    }
    else if (IS_IND_M(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int32_t) get_2_bytes(vm, cur->pc + tmp));
    }
    return (0);
}

void    load_to_reg(t_process *cur,int reg_n, u_int32_t val)
{
    cur->reg[reg_n][0] = (val >> 24) & 0xFF;
    cur->reg[reg_n][1] = (val >> 16) & 0xFF;
    cur->reg[reg_n][2] = (val >> 8) & 0xFF;
    cur->reg[reg_n][3] =  val & 0xFF;
}