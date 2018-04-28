/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:02 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	live_operation(t_VM *machine, t_process *cur)
{
	int32_t player;
    u_int8_t  t_ind[4];
    int i;

    i = 0;
    while (i < REG_SIZE)
    {
        t_ind[i] = machine->memory[(cur->pc + 1 + i) % MEM_SIZE];
        i++;
    }
    player = REVERSE_4_BYTES(*(int32_t *)&t_ind[0]) * -1 - 1;
	if (player < machine->players_qnt && player >= 0)
	{
		machine->player[player].last_live = machine->cycle;
		machine->player[player].live_cur_period++;
        machine->nbr_live++;
        cur->im_alive = 1;
		machine->winner = player;
        if (cur->pc + 4 < MEM_SIZE )
            cur->pc = (cur->pc + 5) % MEM_SIZE;
        else
            cur->pc = (cur->pc + 4) % MEM_SIZE;
	}
	else
		cur->pc++;
}