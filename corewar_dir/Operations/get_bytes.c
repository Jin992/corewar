/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:28:42 by earteshc          #+#    #+#             */
/*   Updated: 2018/05/09 17:28:47 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

u_int16_t		get_2_bytes(t_vm *vm, int pos)
{
	u_int16_t	res;
	u_int8_t	bytes[2];

	ft_bzero(bytes, 2);
	bytes[0] = vm->memory[pos % MEM_SIZE];
	bytes[1] = vm->memory[(pos + 1) % MEM_SIZE];
	res = *(u_int16_t*)&bytes[0];
	return (REVERSE_2_BYTES(res));
}

u_int32_t		get_4_bytes(t_vm *vm, int pos)
{
	u_int32_t	res;
	u_int8_t	bytes[4];

	ft_bzero(bytes, 4);
	bytes[0] = vm->memory[pos % MEM_SIZE];
	bytes[1] = vm->memory[(pos + 1) % MEM_SIZE];
	bytes[2] = vm->memory[(pos + 2) % MEM_SIZE];
	bytes[3] = vm->memory[(pos + 3) % MEM_SIZE];
	res = *(u_int32_t*)&bytes[0];
	return (REVERSE_4_BYTES(res));
}

int				get_reg(int x)
{
	if (x >= 1 && x < 17)
		return (1);
	return (0);
}

void			load_to_reg(t_process *cur, int reg_n, u_int32_t val)
{
	if (get_reg(reg_n + 1))
	{
		cur->reg[reg_n][0] = (val >> 24) & 0xFF;
		cur->reg[reg_n][1] = (val >> 16) & 0xFF;
		cur->reg[reg_n][2] = (val >> 8) & 0xFF;
		cur->reg[reg_n][3] = val & 0xFF;
	}
}

u_int32_t		first_operand(t_vm *vm, t_process *cur, int *shift)
{
	if (IS_REG_S(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 1;
		if (get_reg(vm->memory[(cur->pc + 2) % MEM_SIZE]))
		{
			return (REVERSE_4_BYTES(*(u_int32_t*)\
				&cur->reg[vm->memory[(cur->pc + 2) % MEM_SIZE] - 1][0]));
		}
		return (0);
	}
	else if (IS_DIR_S(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 4;
		return (get_4_bytes(vm, cur->pc + 2));
	}
	else if (IS_IND_S(vm->memory[overla(cur->pc + 1)]))
	{
		*shift += 2;
		return ((u_int32_t)get_2_bytes(vm, cur->pc + 2));
	}
	return (0);
}
