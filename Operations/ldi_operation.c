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

void	ldi_operation(t_VM *vm, t_process *cur)
{
    u_int32_t f1;
    u_int32_t f2;
    int shift;

    shift = 1;
    if (IS_REG_E(vm->memory[OVERLAP(cur->pc + 1)]) && !IS_IND_S(vm->memory[OVERLAP(cur->pc + 1)]))
    {
        f1 = first_operand(vm, cur, &shift);
        f2 = second_operand(vm, cur, &shift);
        load_to_reg(cur, (int) vm->memory[OVERLAP(cur->pc + shift + 1)] - 1, get_4_bytes(vm, OVERLAP((f1 + f2) % IDX_MOD + cur->pc)));
        move_pc(cur, shift + 2);
    }
    else if (IS_REG_E(vm->memory[OVERLAP(cur->pc + 1)]) && IS_IND_S(vm->memory[OVERLAP(cur->pc + 1)]))
        {
            shift = 3;
            f1 = get_4_bytes(vm, vm->memory[OVERLAP(get_2_bytes(vm, OVERLAP(cur->pc + 2)))]) % IDX_MOD;
            f2 = second_operand(vm, cur, &shift);
            load_to_reg(cur, (int) vm->memory[OVERLAP(cur->pc + shift + 1)] - 1, get_4_bytes(vm, OVERLAP((f1 + f2) % IDX_MOD + cur->pc)));
            move_pc(cur, shift + 2);
        }
    else
        move_pc(cur, 1);
}