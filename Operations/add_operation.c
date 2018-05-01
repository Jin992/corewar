/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:38 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:27 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void		add_operation(t_VM *vm, t_process *cur)
{
	int i;
	u_int8_t	bytes[4];
	u_int32_t 	res;

	ft_bzero(bytes, 4);
	if (IS_REG_S(vm->memory[cur->pc + 1]) && IS_REG_M(vm->memory[cur->pc + 1]) && IS_REG_E(vm->memory[cur->pc + 1]))
	{
        if (vm->memory[(cur->pc + 2) % MEM_SIZE] > 15 || vm->memory[(cur->pc + 3) % MEM_SIZE] > 15 || vm->memory[(cur->pc + 4) % MEM_SIZE] > 15)
        {
            cur->pc = (cur->pc + 5) % MEM_SIZE;
            return ;
        }
		res = REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[vm->memory[(cur->pc + 2) % MEM_SIZE]]) + REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[vm->memory[(cur->pc + 3) % MEM_SIZE]]);
		bytes[0] = (res >> 24) & 0xFF;
		bytes[1] = (res >> 16) & 0xFF;
		bytes[2] = (res >> 8) & 0xFF;
		bytes[3] = res & 0xFF;
		i = -1;
		while (++i < REG_SIZE)
			cur->reg[vm->memory[(cur->pc + 4) % MEM_SIZE]][i] = bytes[i];
		if (REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[vm->memory[(cur->pc + 4) % MEM_SIZE]]) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
		cur->pc = (cur->pc + 5) % MEM_SIZE;
	}
	else
		cur->pc++;
}
