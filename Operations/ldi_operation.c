/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:33:37 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

u_int16_t first_operand_3(t_VM *vm, t_process *cur, int *shift)
{
    int tmp;

    tmp = *shift + 1;
    if (IS_REG_S(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 1;
        return ((u_int16_t) (u_int8_t ) \
        cur->reg[vm->memory[(cur->pc + 2) % MEM_SIZE]]);
    }
    else if (IS_DIR_S(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return (u_int16_t)(get_2_bytes(vm, cur->pc + tmp));
    }
    else if (IS_IND_S(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int16_t) get_2_bytes(vm, cur->pc + tmp));
    }
    return (0);
}

u_int16_t second_operand_3(t_VM *vm, t_process *cur, int *shift)
{
    int tmp;

    tmp = *shift + 1;
    if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 1;
        return ((u_int16_t) (u_int8_t) \
        cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE]]);
    }
    else if (IS_DIR_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int16_t)(get_2_bytes(vm, cur->pc + tmp)));
    }
    else if (IS_IND_M(vm->memory[overla(cur->pc + 1)]))
    {
        *shift += 2;
        return ((u_int16_t) get_2_bytes(vm, cur->pc + tmp));
    }
    return (0);
}

void	ldi_operation(t_VM *vm, t_process *cur)
{
    u_int32_t f1;
    u_int32_t f2;
    int shift;
    int i;

    shift = 1;
    i = 0;
    if (IS_REG_E(vm->memory[overla(cur->pc + 1)]) && !IS_IND_S(vm->memory[overla(cur->pc + 1)]))
    {
        f1 = first_operand_3(vm, cur, &shift);
        f2 = second_operand_3(vm, cur, &shift);
         //printf("f1 %d f2 %d total %d\n", f1, f2, overla((f1 + f2) % IDX_MOD));
      //exit(0);
        //load_to_reg(cur, (int) vm->memory[overla(cur->pc + shift + 1)] - 1, overla(((f1 + f2) % IDX_MOD + cur->pc)));
        while (i < REG_SIZE)
        {
            cur->reg[vm->memory[overla(cur->pc + shift + 1)] - 1][i] = vm->memory[overla(((f1 + f2) % IDX_MOD + cur->pc) + i)];
            i++;
        }
        move_pc(cur, shift + 2);
    }
    else if (IS_REG_E(vm->memory[overla(cur->pc + 1)]) && IS_IND_S(vm->memory[overla(cur->pc + 1)]))
        {
            shift = 3;
            f1 = get_4_bytes(vm, vm->memory[overla(get_2_bytes(vm, overla(cur->pc + 2)))]) % IDX_MOD;
            f2 = second_operand_3(vm, cur, &shift);
            load_to_reg(cur, (int) vm->memory[overla(cur->pc + shift + 1)] - 1, overla((f1 + f2) % IDX_MOD + cur->pc));
            move_pc(cur, shift + 2);
        }
    else
        move_pc(cur, 1);
}