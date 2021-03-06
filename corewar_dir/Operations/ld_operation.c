/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:18 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:46:45 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

static void		dir_reg(t_vm *vm, t_process *cur, int i)
{
	if (get_reg(vm->memory[(cur->pc + 6) % MEM_SIZE]))
	{
		while (++i < 4)
			cur->reg[vm->memory[(cur->pc + 6) % MEM_SIZE] - 1][i] = \
			vm->memory[((cur->pc + 2) + i) % MEM_SIZE];
		if (REVERSE_4_BYTES(*(u_int32_t *)&cur->reg[vm->memory[(cur->pc + 6)\
		% MEM_SIZE] - 1]) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
	}
}

static void		ind_reg(t_vm *vm, t_process *cur, int i)
{
	short	t_ind;

	t_ind = get_idx_mod(REVERSE_2_BYTES(*(u_int16_t *)\
		&vm->memory[cur->pc % MEM_SIZE + 2]));
	if (get_reg(vm->memory[(cur->pc + 4) % MEM_SIZE]))
	{
		while (++i < REG_SIZE)
			cur->reg[vm->memory[(cur->pc + 4) % MEM_SIZE] - 1][i] = \
			vm->memory[((cur->pc + t_ind) + i) % MEM_SIZE];
		if (REVERSE_4_BYTES(*(u_int32_t *)&cur->reg[vm->memory[(cur->pc + 4)\
		% MEM_SIZE] - 1]) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
	}
}

void			ld_operation(t_vm *vm, t_process *cur)
{
	int		i;

	i = -1;
	if (IS_DIR_S(vm->memory[(cur->pc + 1) % MEM_SIZE])
		&& IS_REG_M(vm->memory[(cur->pc + 1) % MEM_SIZE]))
		dir_reg(vm, cur, i);
	else if (IS_IND_S((u_int8_t)vm->memory[(cur->pc + 1) % MEM_SIZE])
		&& IS_REG_M((u_int8_t)vm->memory[(cur->pc + 1) % MEM_SIZE]))
		ind_reg(vm, cur, i);
	move_pc(cur, vm, 0, 2);
}
