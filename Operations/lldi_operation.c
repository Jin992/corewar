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

void	lldi_operation(t_VM *vm, t_process *cur)
{
	u_int32_t f1;
	u_int32_t f2;
	int shift;

	shift = 1;
	if (IS_REG_E(vm->memory[overla(cur->pc + 1)]) && !IS_IND_S(vm->memory[overla(cur->pc + 1)]))
	{
		f1 = first_operand(vm, cur, &shift);
		f2 = second_operand(vm, cur, &shift);
		load_to_reg(cur, (int) vm->memory[overla(cur->pc + shift + 1)] - 1, get_4_bytes(vm, overla((f1 + f2) + cur->pc)));
		if ((get_4_bytes(vm, overla((f1 + f2) + cur->pc))) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
		move_pc(cur, shift + 2);
	}
	else if (IS_REG_E(vm->memory[overla(cur->pc + 1)]) && IS_IND_S(vm->memory[overla(cur->pc + 1)]))
	{
		shift = 3;
		f1 = get_4_bytes(vm, vm->memory[overla(get_2_bytes(vm, overla(cur->pc + 2)))]);
		f2 = second_operand(vm, cur, &shift);
		load_to_reg(cur, (int) vm->memory[overla(cur->pc + shift + 1)] - 1, get_4_bytes(vm, overla((f1 + f2) + cur->pc)));
		if ((get_4_bytes(vm, overla((f1 + f2) % IDX_MOD + cur->pc))) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
		move_pc(cur, shift + 2);
	}
	else
		move_pc(cur, 1);
}

