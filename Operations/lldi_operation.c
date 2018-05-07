/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:34:39 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
u_int32_t second_operand_3(t_VM *vm, t_process *cur, int *shift);
u_int32_t first_operand_3(t_VM *vm, t_process *cur, int *shift);

void	lldi_operation(t_VM *vm, t_process *cur)
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
        while (i < REG_SIZE)
        {
            cur->reg[vm->memory[overla(cur->pc + shift + 1)] - 1][i] = vm->memory[overla(((f1 + f2) + cur->pc) + i)];
            i++;
        }
    }
    else if (IS_REG_E(vm->memory[overla(cur->pc + 1)]) && IS_IND_S(vm->memory[overla(cur->pc + 1)]))
    {
            shift = 3;
            f1 = get_2_bytes(vm, vm->memory[overla(get_2_bytes(vm, overla(cur->pc + 2)))]) ;
            f2 = second_operand_3(vm, cur, &shift);
            load_to_reg(cur, (int) vm->memory[overla(cur->pc + shift + 1)] - 1, overla((f1 + f2) + cur->pc));
    }
    move_pc(cur, vm, 2, 3);
}

