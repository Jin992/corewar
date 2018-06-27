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

static void		reg_dir(t_vm *vm, t_process *cur)
{
	short		f1;
	short		f2;
	int			shift;
	int			i;

	shift = 1;
	i = 0;
	f1 = first_operand_3(vm, cur, &shift);
	f2 = second_operand_3(vm, cur, &shift);
	if (check_register(vm, cur))
		while (i < REG_SIZE)
		{
			cur->reg[vm->memory[overla(cur->pc + shift + 1)] - 1][i] = \
			vm->memory[overla(((f1 + f2) + cur->pc) + i)];
			i++;
		}
}

static void		reg_ind(t_vm *vm, t_process *cur)
{
	short		f1;
	short		f2;
	int			shift;

	shift = 3;
	f1 = get_4_bytes(vm, (get_idx_mod(\
		get_2_bytes(vm, overla(cur->pc + 3))) + cur->pc) % MEM_SIZE);
	f2 = second_operand_3(vm, cur, &shift);
	if (check_register(vm, cur))
	{
		load_to_reg(cur, (int)vm->memory[overla(cur->pc + shift + 1)]\
			- 1, overla((f1 + f2) + cur->pc));
		if (REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[\
			vm->memory[overla(cur->pc + shift + 1)] - 1]) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
	}
}

void			lldi_operation(t_vm *vm, t_process *cur)
{
	if (check_c_octal_ldi(vm->memory[overla(cur->pc + 1)]))
	{
		if (IS_REG_E(vm->memory[overla(cur->pc + 1)])
			&& !IS_IND_S(vm->memory[overla(cur->pc + 1)]))
			reg_dir(vm, cur);
		else if (IS_REG_E(vm->memory[overla(cur->pc + 1)])
			&& IS_IND_S(vm->memory[overla(cur->pc + 1)]))
			reg_ind(vm, cur);
	}
	move_pc(cur, vm, 2, 3);
}
