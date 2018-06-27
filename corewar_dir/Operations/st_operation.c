/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:28 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:53:59 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

static void		reg_reg(t_vm *vm, t_process *cur, int pos)
{
	int i;

	i = -1;
	if (get_reg(vm->memory[(cur->pc + 3) % MEM_SIZE])
		&& get_reg(vm->memory[(cur->pc + 2) % MEM_SIZE]))
		while (++i < 4)
			cur->reg[vm->memory[(cur->pc + 3) % MEM_SIZE] - 1][i] = \
		cur->reg[pos][i];
}

static void		reg_ind(t_vm *vm, t_process *cur, int pos)
{
	int		i;
	short	t_ind;

	i = -1;
	t_ind = get_idx_mod(get_2_bytes(vm, cur->pc + 3));
	if (get_reg(vm->memory[(cur->pc + 2) % MEM_SIZE]))
	{
		while (++i < 4)
		{
			vm->memory[((cur->pc + t_ind) + i) % MEM_SIZE] = \
			cur->reg[pos][i];
			vm->memory_color[((cur->pc + t_ind) + i) % MEM_SIZE] = \
			cur->color;
		}
	}
}

void			st_operation(t_vm *vm, t_process *cur)
{
	int pos;

	pos = vm->memory[(cur->pc + 2) % MEM_SIZE] - 1;
	cur->value = vm->memory[overla(cur->pc + 1)];
	if (IS_REG_S(vm->memory[(cur->pc + 1) % MEM_SIZE])
		&& IS_REG_M(vm->memory[(cur->pc + 1) % MEM_SIZE]))
		reg_reg(vm, cur, pos);
	else if (IS_REG_S(vm->memory[(cur->pc + 1) % MEM_SIZE])
		&& IS_IND_M(vm->memory[(cur->pc + 1) % MEM_SIZE]))
		reg_ind(vm, cur, pos);
	move_pc_st(cur, vm, 0, 2);
}
