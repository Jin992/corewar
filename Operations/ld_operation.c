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

void ld_operation(t_VM *machine, t_process *cur)
{
	int 		i;
	u_int16_t	t_ind;

	i = -1;
	if (IS_DIR_S(machine->memory[cur->pc + 1]) && IS_REG_M(machine->memory[cur->pc + 1]))
	{
		while (++i < 4)
			cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 6]][i] = machine->memory[(cur->pc + 2) + i];
//		mvwprintw(machine->menu, 0, 250, "T_DIR memory cell %d Regitser 1: [%hhu %hhu %hhu %hhu]\n", *(u_int8_t *)&machine->memory[cur->pc + 6], cur->reg[2][0], cur->reg[2][1], cur->reg[2][2], cur->reg[2][3]);
		cur->pc += 7;
	}
	else if (IS_IND_S((u_int8_t)machine->memory[cur->pc + 1]) && IS_REG_M((u_int8_t)machine->memory[cur->pc + 1]))
	{
		t_ind = REVERSE_2_BYTES(*(u_int16_t *)&machine->memory[cur->pc + 2]) % IDX_MOD;
        if (*(u_int32_t *)&cur->reg[machine->memory[cur->pc + 4]] == 0)
            cur->carry = 1;
        mvwprintw(machine->menu, 30, 0, "Carry %d", cur->carry );
        mvwprintw(machine->menu, 31, 0, "ind %d", machine->memory[cur->pc + 4] );
//		mvwprintw(machine->menu, 1, 250, "start spot for t_ind %d\n", (int)t_ind );
		while (++i < 4)
			cur->reg[machine->memory[cur->pc + 4]][i] = machine->memory[(cur->pc + t_ind) + i];
		cur->pc += 5;
	}
    else
        cur->pc++;
//	mvwprintw(machine->menu, 2, 250,"ld_operation\n");
	wrefresh(machine->menu);
	werase(machine->menu);
}
