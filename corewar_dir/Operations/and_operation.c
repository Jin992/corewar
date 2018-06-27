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

int		if_good_reg_start(t_vm *vm, t_process *cur)
{
	if (IS_REG_S(vm->memory[overla(cur->pc + 1)]))
	{
		if (get_reg(vm->memory[(cur->pc + 2) % MEM_SIZE]))
			return (1);
		else
			return (0);
	}
	return (1);
}

int		if_good_reg_midl(t_vm *vm, t_process *cur, int shift)
{
	if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
	{
		if (get_reg(vm->memory[(cur->pc + shift) % MEM_SIZE]))
			return (1);
		else
			return (0);
	}
	return (1);
}

int		if_good_reg_end(t_vm *vm, t_process *cur, int shift)
{
	if (IS_REG_E(vm->memory[overla(cur->pc + 1)]))
	{
		if (get_reg(vm->memory[(cur->pc + shift) % MEM_SIZE]))
			return (1);
		else
			return (0);
	}
	return (1);
}

void	and_operation(t_vm *vm, t_process *cur)
{
	u_int32_t	f1;
	u_int32_t	f2;
	int			shift;

	shift = 1;
	if (check_c_octal_or(vm->memory[overla(cur->pc + 1)]))
	{
		if (IS_REG_E(vm->memory[overla(cur->pc + 1)]))
		{
			f1 = first_operand(vm, cur, &shift);
			f2 = second_operand(vm, cur, &shift);
			if (if_good_reg_start(vm, cur) && if_good_reg_midl(vm, cur, shift)
				&& if_good_reg_end(vm, cur, shift + 1))
			{
				load_to_reg(cur, (int)vm->memory[overla(cur->pc + shift + 1)]\
				- 1, f1 & f2);
				if ((f1 & f2) == 0)
					cur->carry = 1;
				else
					cur->carry = 0;
			}
		}
	}
	move_pc(cur, vm, 0, 3);
}
