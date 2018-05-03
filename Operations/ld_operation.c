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
#include <stdio.h>

void ld_operation(t_VM *vm, t_process *cur)
{
	int 		i;
	u_int16_t	t_ind;

	i = -1;
	if (IS_DIR_S(vm->memory[(cur->pc + 1) % MEM_SIZE ]) && IS_REG_M(vm->memory[(cur->pc + 1) % MEM_SIZE]))
	{
		if (get_reg(vm->memory[(cur->pc + 6) % MEM_SIZE ]))
		{
			while (++i < 4)
				cur->reg[vm->memory[(cur->pc + 6) % MEM_SIZE ] - 1][i] = vm->memory[((cur->pc + 2) + i) % MEM_SIZE];
			if (REVERSE_4_BYTES(*(u_int32_t *)&cur->reg[vm->memory[(cur->pc + 6) % MEM_SIZE]]) == 0)
				cur->carry = 1;
			else
				cur->carry = 0;
		}
		cur->pc = (cur->pc + 7) % MEM_SIZE;
	}
	else if (IS_IND_S((u_int8_t)vm->memory[(cur->pc + 1) % MEM_SIZE]) && IS_REG_M((u_int8_t)vm->memory[(cur->pc + 1) % MEM_SIZE]))
	{
		t_ind = REVERSE_2_BYTES(*(u_int16_t *)&vm->memory[cur->pc % MEM_SIZE + 2]) % IDX_MOD;
		if (get_reg(vm->memory[(cur->pc + 4) % MEM_SIZE ]))
		{
			while (++i < REG_SIZE)
				cur->reg[vm->memory[(cur->pc + 4) % MEM_SIZE] - 1][i] = vm->memory[((cur->pc + t_ind) + i) % MEM_SIZE];
        	if (REVERSE_4_BYTES(*(u_int32_t *)&cur->reg[vm->memory[(cur->pc + 4) % MEM_SIZE]]) == 0)
        	    cur->carry = 1;
        	else
        	    cur->carry = 0;
    	}
		cur->pc = (cur->pc + 5) % MEM_SIZE;
	}
    else
        cur->pc++;
}
