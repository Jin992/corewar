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
	if (IS_REG_S(machine->memory[cur->pc + 1]) && IS_REG_M(machine->memory[cur->pc + 1]))
	{
		while (++i < 4)
			cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 2]][i] = cur->reg[*(u_int8_t *)&machine->memory[cur->pc + 3]][i];
		cur->pc += 4;
		mvwprintw(machine->menu, 0, 250, "im in reg reg \n");
	}
	else if (IS_REG_S(machine->memory[cur->pc + 1]) && IS_IND_M(machine->memory[cur->pc + 1]))
	{
		t_ind = REVERSE_2_BYTES(*(u_int16_t *)&machine->memory[cur->pc + 3]) % IDX_MOD;
		mvwprintw(machine->menu, 1, 250, "start spot for t_ind %.2x\n", t_ind );
		while (++i < 4)
		{
			machine->memory[((cur->pc + t_ind) + i) % MEM_SIZE] = cur->reg[*(u_int8_t *) &machine->memory[cur->pc + 2]][i];
			mvwprintw(machine->main_field, 1, 80, "im in reg ind \n");
		}
		cur->pc += 5;
	}
    else
        cur->pc++;
	mvwprintw(machine->menu, 3, 250, "st_operation\n");
	wrefresh(machine->menu);
	werase(machine->menu);
}