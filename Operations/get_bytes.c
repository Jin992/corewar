
#include "../includes/operations.h"

u_int16_t get_2_bytes(t_VM *vm, int pos)
{
    u_int16_t	res;
    u_int8_t	bytes[2];

    ft_bzero(bytes, 2);
    bytes[0] = vm->memory[pos % MEM_SIZE];
    bytes[1] = vm->memory[(pos + 1) % MEM_SIZE];
    res = *(u_int16_t*)&bytes[0];
    return  (REVERSE_2_BYTES(res));
}

u_int32_t get_4_bytes(t_VM *vm, int pos)
{
    u_int32_t	res;
    u_int8_t	bytes[4];

    ft_bzero(bytes, 4);
    bytes[0] = vm->memory[pos % MEM_SIZE];
    bytes[1] = vm->memory[(pos + 1) % MEM_SIZE];
    bytes[2] = vm->memory[(pos + 2) % MEM_SIZE];
    bytes[3] = vm->memory[(pos + 3) % MEM_SIZE];
    res = *(u_int32_t*)&bytes[0];
    return  (REVERSE_4_BYTES(res));
}

int     check_start(u_int8_t digit, int label)
{
    if (IS_REG_S(digit))
        return (1);
    if (IS_DIR_S(digit))
        return (4 - label);
    if (IS_IND_S(digit))
        return (2);
    return (0);
}
int     check_middle(u_int8_t digit, int label)
{
    if (IS_REG_M(digit))
        return (1);
    if (IS_DIR_M(digit))
        return (4 - label);
    if (IS_IND_M(digit))
        return (2);
    return (0);
}
int     check_end(u_int8_t digit, int label)
{
    if (IS_REG_E(digit))
        return (1);
    if (IS_DIR_E(digit))
        return (4 - label);
    if (IS_IND_E(digit))
        return (2);
    return (0);
}

void    move_pc(t_process *cur, t_VM *vm, int label, int params)
{
    int shift[3];

    ft_bzero(shift, 3);

    shift[0] = check_start(vm->memory[(cur->pc + 1) % MEM_SIZE], label);
    shift[1] = check_middle(vm->memory[(cur->pc + 1) % MEM_SIZE], label);
    shift[2] = check_end(vm->memory[(cur->pc + 1) % MEM_SIZE], label);
    // if (shift[0] == 0 || shift[1] == 0 || shift[2] == 0)
    // {
    //     cur->pc = (cur->pc + 2) % MEM_SIZE;
    //     return ;
    // }
    if (params == 2)
        cur->pc = (cur->pc + 2 + shift[0] + shift[1]) % MEM_SIZE;
    else
        cur->pc = (cur->pc + 2 + shift[0] + shift[1] + shift[2]) % MEM_SIZE;
}

u_int32_t first_operand(t_VM *vm, t_process *cur, int *shift)
{
    if (IS_REG_S(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 1;
        return (REVERSE_4_BYTES(*(u_int32_t*) &cur->reg[vm->memory[(cur->pc + 2) % MEM_SIZE] - 1][0]));
    }
    else if (IS_DIR_S(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 4;
        return (get_4_bytes(vm, cur->pc + 2));
    }
    else if (IS_IND_S(vm->memory[overla(cur->pc + 1)]))
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
    if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 1;
        return (REVERSE_4_BYTES(*(u_int32_t*)
        &cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1][0]));
    }
    else if (IS_DIR_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 4;
        return (get_4_bytes(vm, cur->pc + tmp));
    }
    else if (IS_IND_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int32_t) get_2_bytes(vm, cur->pc + tmp));
    }
    return (0);
}

u_int32_t first_operand_2(t_VM *vm, t_process *cur, int *shift)
{
    int tmp;

    tmp = *shift + 1;
    if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 1;
        return (REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[vm->memory[(cur->pc + 3) % MEM_SIZE] - 1]));
    }
    else if (IS_DIR_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return (u_int16_t)(get_2_bytes(vm, cur->pc + tmp));
        //return (*(u_int16_t*)&vm->memory[cur->pc + 2]);
    }
    else if (IS_IND_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int16_t) get_2_bytes(vm, cur->pc + tmp));
    }
    return (0);
}

u_int32_t second_operand_2(t_VM *vm, t_process *cur, int *shift)
{
    int tmp;

    tmp = *shift + 1;
    if (IS_REG_E(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 1;
        return (REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1]));
    }
    else if (IS_DIR_E(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int16_t)(get_2_bytes(vm, cur->pc + tmp)));
    }
    else if (IS_IND_E(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int16_t) get_2_bytes(vm, cur->pc + tmp));
    }
    return (0);
}

void    load_to_reg(t_process *cur,int reg_n, u_int32_t val)
{
    if (get_reg(reg_n + 1))
    {
        cur->reg[reg_n][0] = (val >> 24) & 0xFF;
        cur->reg[reg_n][1] = (val >> 16) & 0xFF;
        cur->reg[reg_n][2] = (val >> 8) & 0xFF;
        cur->reg[reg_n][3] =  val & 0xFF;
    }
}