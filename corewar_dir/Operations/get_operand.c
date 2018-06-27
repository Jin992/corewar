/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:06:32 by earteshc          #+#    #+#             */
/*   Updated: 2018/05/09 17:06:35 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

int			first_operand_3(t_vm *vm, t_process *cur, int *shift)
{
	int tmp;

	tmp = *shift + 1;
	if (IS_REG_S(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 1;
		if (get_reg(vm->memory[(cur->pc + tmp) % MEM_SIZE]))
		{
			return (REVERSE_4_BYTES(*(u_int32_t*)\
				&cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1]));
		}
		return (0);
	}
	else if (IS_DIR_S(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)get_2_bytes(vm, cur->pc + tmp));
	}
	else if (IS_IND_S(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)get_2_bytes(vm, cur->pc + tmp));
	}
	return (0);
}

int			second_operand_3(t_vm *vm, t_process *cur, int *shift)
{
	int tmp;

	tmp = *shift + 1;
	if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 1;
		if (get_reg(vm->memory[(cur->pc + tmp) % MEM_SIZE]))
		{
			return (REVERSE_4_BYTES(*(u_int32_t*)\
				&cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1]));
		}
		return (0);
	}
	else if (IS_DIR_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)(get_2_bytes(vm, cur->pc + tmp)));
	}
	else if (IS_IND_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)get_2_bytes(vm, cur->pc + tmp));
	}
	return (0);
}

int			first_operand_2(t_vm *vm, t_process *cur, int *shift)
{
	int tmp;

	tmp = *shift + 1;
	if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 1;
		if (get_reg(vm->memory[(cur->pc + tmp) % MEM_SIZE]))
		{
			return (REVERSE_4_BYTES(*(u_int32_t*)\
				&cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1]));
		}
		return (0);
	}
	else if (IS_DIR_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return (short)(get_2_bytes(vm, cur->pc + tmp));
	}
	else if (IS_IND_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)get_2_bytes(vm, cur->pc + tmp));
	}
	return (0);
}

int			second_operand_2(t_vm *vm, t_process *cur, int *shift)
{
	int tmp;

	tmp = *shift + 1;
	if (IS_REG_E(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 1;
		if (get_reg(vm->memory[(cur->pc + tmp) % MEM_SIZE]))
		{
			return (REVERSE_4_BYTES(*(int32_t*)\
				&cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1]));
		}
		return (0);
	}
	else if (IS_DIR_E(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)(get_2_bytes(vm, cur->pc + tmp)));
	}
	else if (IS_IND_E(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((short)get_2_bytes(vm, cur->pc + tmp));
	}
	return (0);
}

u_int32_t	second_operand(t_vm *vm, t_process *cur, int *shift)
{
	int tmp;

	tmp = *shift + 1;
	if (IS_REG_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 1;
		if (get_reg(vm->memory[(cur->pc + tmp) % MEM_SIZE]))
		{
			return (REVERSE_4_BYTES(*(u_int32_t*)
				&cur->reg[vm->memory[(cur->pc + tmp) % MEM_SIZE] - 1][0]));
		}
		return (0);
	}
	else if (IS_DIR_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 4;
		return (get_4_bytes(vm, cur->pc + tmp));
	}
	else if (IS_IND_M(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((u_int32_t)get_2_bytes(vm, cur->pc + tmp));
	}
	return (0);
}
