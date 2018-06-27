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

void	print_live(t_vm *vm, int player)
{
	if (vm->visual == 0 && vm->aff == 1)
	{
		ft_printf("A process shows that player %d (%s) is alive.\n",
		player + 1, vm->player[player].name);
	}
	else if (vm->aff == 1)
	{
		wattron(vm->menu, COLOR_PAIR(player + 1));
		mvwprintw(vm->menu, 23, 0, \
		"A process shows that player %d (%10s) is alive.\n",
		player + 1, vm->player[player].name);
		wattroff(vm->menu, COLOR_PAIR(player + 1));
	}
}

void	live_operation(t_vm *vm, t_process *cur)
{
	int32_t		player;
	u_int8_t	t_ind[4];
	int			i;

	i = 0;
	while (i < REG_SIZE)
	{
		t_ind[i] = vm->memory[(cur->pc + 1 + i) % MEM_SIZE];
		i++;
	}
	player = REVERSE_4_BYTES(*(int32_t *)&t_ind[0]) * -1 - 1;
	cur->im_alive = 1;
	vm->nbr_live++;
	if (player < vm->players_qnt && player >= 0)
	{
		vm->player[player].last_live = vm->cycle + 1;
		vm->player[player].live_cur_period++;
		vm->winner = player;
		print_live(vm, player);
	}
	cur->pc = (cur->pc + 5) % MEM_SIZE;
}
