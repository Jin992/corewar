/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:24:17 by earteshc          #+#    #+#             */
/*   Updated: 2018/05/09 17:24:19 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

int			check_start(u_int8_t digit, int label)
{
	if (IS_REG_S(digit))
		return (1);
	if (IS_DIR_S(digit))
		return (4 - label);
	if (IS_IND_S(digit))
		return (2);
	return (0);
}

int			check_middle(u_int8_t digit, int label)
{
	if (IS_REG_M(digit))
		return (1);
	if (IS_DIR_M(digit))
		return (4 - label);
	if (IS_IND_M(digit))
		return (2);
	return (0);
}

int			check_end(u_int8_t digit, int label)
{
	if (IS_REG_E(digit))
		return (1);
	if (IS_DIR_E(digit))
		return (4 - label);
	if (IS_IND_E(digit))
		return (2);
	return (0);
}

void		move_pc(t_process *cur, t_vm *vm, int label, int params)
{
	int shift[3];

	ft_bzero(shift, 3);
	shift[0] = check_start(vm->memory[(cur->pc + 1) % MEM_SIZE], label);
	shift[1] = check_middle(vm->memory[(cur->pc + 1) % MEM_SIZE], label);
	shift[2] = check_end(vm->memory[(cur->pc + 1) % MEM_SIZE], label);
	if (params == 1)
		cur->pc = (cur->pc + 2 + shift[0]) % MEM_SIZE;
	else if (params == 2)
		cur->pc = (cur->pc + 2 + shift[0] + shift[1]) % MEM_SIZE;
	else
		cur->pc = (cur->pc + 2 + shift[0] + shift[1] + shift[2]) % MEM_SIZE;
}

void		move_pc_st(t_process *cur, t_vm *vm, int label, int params)
{
	int shift[3];

	ft_bzero(shift, 3);
	shift[0] = check_start(cur->value, label);
	shift[1] = check_middle(cur->value, label);
	shift[2] = check_end(cur->value, label);
	(void)vm;
	if (params == 1)
		cur->pc = (cur->pc + 2 + shift[0]) % MEM_SIZE;
	else if (params == 2)
		cur->pc = (cur->pc + 2 + shift[0] + shift[1]) % MEM_SIZE;
	else
		cur->pc = (cur->pc + 2 + shift[0] + shift[1] + shift[2]) % MEM_SIZE;
}
