/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:48 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:43:11 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void sub_operation(t_VM *machine, t_process *cur)
{
	int i;
	u_int8_t	bytes[4];
	u_int32_t 	res;

	ft_bzero(bytes, 4);
	if (IS_REG_S(machine->memory[cur->pc + 1]) && IS_REG_M(machine->memory[cur->pc + 1]) && IS_REG_E(machine->memory[cur->pc + 1]))
	{
		if (machine->memory[cur->pc + 2] > 15 || machine->memory[cur->pc  + 3] > 15 || machine->memory[cur->pc + 4] > 15)
		{
			cur->pc += 5;
			return ;
		}
		res = REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[machine->memory[cur->pc + 2]]) - REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[machine->memory[cur->pc + 3]]);
		bytes[0] = (res >> 24) & 0xFF;
		bytes[1] = (res >> 16) & 0xFF;
		bytes[2] = (res >> 8) & 0xFF;
		bytes[3] = res & 0xFF;
		i = -1;
		while (++i < REG_SIZE)
			cur->reg[machine->memory[cur->pc + 4]][i] = bytes[i];
		if (REVERSE_4_BYTES(*(u_int32_t*)&cur->reg[machine->memory[cur->pc + 4]]) == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
		cur->pc += 5;
	}
	else
		cur->pc++;
}
