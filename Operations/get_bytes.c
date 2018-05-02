
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