/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:58 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	and_operation(t_VM *vm, t_process *cur)
{
	u_int32_t f1;
	u_int32_t f2;
	int shift;

	shift = 1;
	if (IS_REG_E(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		f1 = first_operand(vm, cur, &shift);
		f2 = second_operand(vm, cur, &shift);
		load_to_reg(cur, (int) vm->memory[OVERLAP(cur->pc + shift + 1)] - 1, f1 & f2);
		move_pc(cur, shift + 2);
		if ((f1 & f2) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
	}
	else
		move_pc(cur, 1);
}