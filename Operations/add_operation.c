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

void		add_operation(t_VM *machine, t_process *cur)
{
	int i;

	i = 0;
	if (IS_REG_S(machine->memory[cur->pc + 1]) && IS_REG_M(machine->memory[cur->pc + 1]) && IS_REG_E(machine->memory[cur->pc + 1]))
	{
		while (i < 4)
			cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 4]][i] = cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 2]][i] + cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 3]][i];
		if (REVERSE_4_BYTES(*(u_int16_t*)&cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 4]]) == 0)
			cur->carry = 1;
		cur->pc += 5;
	}
	int shift = 0;
	ft_printf("add_operation\n");
	cur->pc += shift;
}
