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

#define OVERLAP(x)(x % MEM_SIZE)

#include "../includes/operations.h"
u_int32_t first_operand(t_VM *vm, t_process *cur, int *shift)
{
	if (IS_REG_S(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		*shift += 1;
		return ((u_int32_t) REVERSE_4_BYTES(*(u_int32_t *) \
        &cur->reg[vm->memory[(cur->pc + 2) % MEM_SIZE]]));
	}
	else if (IS_DIR_S(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		*shift += 4;
		return (get_4_bytes(vm, cur->pc + 2));
	}
	else if (IS_IND_S(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		*shift += 2;
		return ((u_int32_t) get_2_bytes(vm, cur->pc + 2));
	}
	return (0);
}

u_int32_t second_operand(t_VM *vm, t_process *cur, int *shift)
{
	int tmp;

	tmp = *shift + 1;
	if (IS_REG_M(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		*shift += 1;
		return ((u_int32_t) REVERSE_4_BYTES(*(u_int32_t *) \
        &cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE]]));
	}
	else if (IS_DIR_M(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		*shift += 4;
		return (get_4_bytes(vm, cur->pc + tmp));
	}
	else if (IS_IND_M(vm->memory[OVERLAP(cur->pc + 1)]))
	{
		*shift += 2;
		return ((u_int32_t) get_2_bytes(vm, cur->pc + tmp));
	}
	return (0);
}

void	from_u_int32_to_u_int8_arr(t_process *cur,int reg_n, u_int32_t val)
{
	cur->reg[reg_n][0] = (val >> 24) & 0xFF;
	cur->reg[reg_n][1] = (val >> 16) & 0xFF;
	cur->reg[reg_n][2] = (val >> 8) & 0xFF;
	cur->reg[reg_n][3] =  val & 0xFF;
}

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
		from_u_int32_to_u_int8_arr(cur, (int) vm->memory[OVERLAP(cur->pc + shift + 1)] - 1, f1 & f2);
		move_pc(cur, shift + 2);
	}
	else
		move_pc(cur, 1);
}