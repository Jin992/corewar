/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:18 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/24 15:32:21 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include <stdio.h>

void ld_operation(t_VM *machine, t_process *cur)
{
	int 		i;
	u_int16_t	t_ind;

	i = -1;
	if (IS_DIR_S(machine->memory[cur->pc + 1]) && IS_REG_M(machine->memory[cur->pc + 1]))
	{
		while (++i < 4)
			cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 6]][i] = machine->memory[(cur->pc + 1) + i];
		printf("it works memory cell %d\nRegitser 1 %d %d %d %d", *(u_int8_t *)&machine->memory[cur->pc + 6], cur->reg[1][0], cur->reg[1][1], cur->reg[1][2], cur->reg[1][3]);
		cur->pc += 7;
	}
	else if (IS_IND_S((u_int8_t)machine->memory[cur->pc + 1]) && IS_REG_M((u_int8_t)machine->memory[cur->pc + 1]))
	{
		t_ind = REVERSE_2_BYTES(*(u_int16_t *)&machine->memory[cur->pc + 2]) % IDX_MOD;
		printf("start spot for t_ind %d\n", (int)t_ind );
		while (++i < 4)
			cur->reg[*(u_int16_t *)&machine->memory[cur->pc + 4]][i] = machine->memory[(cur->pc + t_ind) + i];
		cur->pc += 5;
	}
	ft_printf("ld_operation\n");
}
