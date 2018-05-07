/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:33:17 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	xor_operation(t_VM *vm, t_process *cur)
{
	u_int32_t f1;
	u_int32_t f2;
	int shift;

	shift = 1;
	if (IS_REG_E(vm->memory[overla(cur->pc + 1)]))
	{
		f1 = first_operand(vm, cur, &shift);
		f2 = second_operand(vm, cur, &shift);
		if (if_good_reg_start(vm, cur) && if_good_reg_midl(vm, cur, shift))
		{
			load_to_reg(cur, (int) vm->memory[overla(cur->pc + shift + 1)] - 1, (f1 ^ f2));
			if ((f1 ^ f2) == 0)
				cur->carry = 1;
			else
				cur->carry = 0;
		}
	}
	move_pc(cur, vm, 0, 3);
}