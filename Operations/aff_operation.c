/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:35:02 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	aff_operation(t_VM *machine, t_process *cur)
{
	int32_t index;
	u_int8_t  t_ind[4];
	int i;

	i = 0;
	while (i < REG_SIZE)
    {
        t_ind[i] = machine->memory[(cur->pc + 1 + i) % MEM_SIZE];
        i++;
    }
    index = (REVERSE_4_BYTES(*(int32_t *)&t_ind[0]));
    // if (index >= 1 && index <= 16)
    // {
    // 	mvwprintw(machine->menu, 50, 0, "AFF : %C", (REVERSE_4_BYTES(*(int32_t *)&cur->reg[index][0])) % 256);
    // 	wrefresh(machine->menu);
    // }
    cur->pc =  ((cur->pc + 4) % MEM_SIZE);
    
}