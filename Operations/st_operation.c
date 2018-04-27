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

void st_operation(t_VM *machine, t_process *cur)
{
	int i;
	u_int16_t t_ind;

	i = -1;
	if (IS_REG_S(machine->memory[(cur->pc + 1) % MEM_SIZE]) && IS_REG_M(machine->memory[(cur->pc + 1) % MEM_SIZE]))
	{
		while (++i < 4)
			cur->reg[machine->memory[(cur->pc + 3) % MEM_SIZE]][i] = cur->reg[machine->memory[(cur->pc + 2) % MEM_SIZE]][i];
		cur->pc += 4;
	}
	else if (IS_REG_S(machine->memory[(cur->pc + 1) % MEM_SIZE]) && IS_IND_M(machine->memory[(cur->pc + 1) % MEM_SIZE]))
	{
		t_ind = REVERSE_2_BYTES(*(u_int16_t *)&machine->memory[(cur->pc + 3) % MEM_SIZE]) % IDX_MOD;
		while (++i < 4)
			machine->memory[((cur->pc + t_ind) + i) % MEM_SIZE] = cur->reg[machine->memory[(cur->pc + 2) % MEM_SIZE]][i];
		cur->pc += 5;
	}
    else
        cur->pc++;
}