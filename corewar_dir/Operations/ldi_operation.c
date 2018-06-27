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

int		check_register_ldi(t_vm *vm, t_process *cur)
{
	if ((IS_REG_S(vm->memory[overla(cur->pc + 1)])))
	{
		if ((if_good_reg_start(vm, cur)) == 0)
			return (0);
		if ((IS_REG_M(vm->memory[overla(cur->pc + 1)])))
		{
			if ((if_good_reg_midl(vm, cur, 3)) == 0)
				return (0);
			if ((if_good_reg_end(vm, cur, 4)) == 0)
				return (0);
		}
		else if ((if_good_reg_end(vm, cur, 5)) == 0)
			return (0);
	}
	else if ((IS_REG_M(vm->memory[overla(cur->pc + 1)])))
	{
		if ((if_good_reg_midl(vm, cur, 4)) == 0)
			return (0);
		if ((if_good_reg_end(vm, cur, 5)) == 0)
			return (0);
	}
	else if ((if_good_reg_end(vm, cur, 6)) == 0)
		return (0);
	return (1);
}

void	ldi_operation_2(t_vm *vm, t_process *cur)
{
	int		f1;
	int		f2;
	int		shift;

	shift = 4;
	f1 = get_4_bytes(vm, (get_idx_mod(\
		get_2_bytes(vm, overla(cur->pc + 3))) + cur->pc) % MEM_SIZE);
	f2 = second_operand_3(vm, cur, &shift);
	vm->res = ((int)f1 + (int)f2) % IDX_MOD;
	if (check_register_ldi(vm, cur))
		load_to_reg(cur, vm->memory[overla(cur->pc +\
		shift + 1)] - 1, overla(get_idx_mod(vm->res) + cur->pc));
}

void	ldi_operation(t_vm *vm, t_process *cur)
{
	int			f1;
	int			f2;
	int			shift;
	int			i;

	shift = 1;
	i = -1;
	if (check_c_octal_ldi(vm->memory[overla(cur->pc + 1)]))
	{
		if (!IS_IND_S(vm->memory[overla(cur->pc + 1)]))
		{
			f1 = first_operand_3(vm, cur, &shift);
			f2 = second_operand_3(vm, cur, &shift);
			vm->res = ((int)f1 + (int)f2) % IDX_MOD;
			if (check_register_ldi(vm, cur))
				while (++i < REG_SIZE)
				{
					cur->reg[vm->memory[overla(cur->pc + shift + 1)] - 1][i] = \
					vm->memory[overla((get_idx_mod(vm->res) + cur->pc) + i)];
				}
		}
		else
			ldi_operation_2(vm, cur);
	}
	move_pc(cur, vm, 2, 3);
}
