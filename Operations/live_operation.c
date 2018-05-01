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

void    print_live(t_VM *vm, int player) // доробити
{
    if (vm->visual == 0)
    {
        ft_printf("A process shows that player %d (%s) is alive.\n",
        player, vm->player[player].name);
    }
    else
    {
        mvwprintw(vm->menu, 0, 50, "A process shows that player %d (%s) is alive.",
        player, vm->player[player].name);
        wrefresh(vm->menu);
    }
}

void	live_operation(t_VM *vm, t_process *cur)
{
	int32_t player;
    u_int8_t  t_ind[4];
    int i;

    i = 0;
    while (i < REG_SIZE)
    {
        t_ind[i] = vm->memory[(cur->pc + 1 + i) % MEM_SIZE];
        i++;
    }
    player = REVERSE_4_BYTES(*(int32_t *)&t_ind[0]) * -1 - 1;
	if (player < vm->players_qnt && player >= 0)
	{
		vm->player[player].last_live = vm->cycle;
		vm->player[player].live_cur_period++;
        vm->nbr_live++;
        cur->im_alive = 1;
		vm->winner = player;
        print_live(vm, player);
        if (cur->pc + 4 < MEM_SIZE )
            cur->pc = (cur->pc + 5) % MEM_SIZE;
        else
            cur->pc = (cur->pc + 4) % MEM_SIZE;
	}
	else
		cur->pc++;
}