/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:52:27 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 13:52:29 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_winner(t_vm *vm)
{
	werase(vm->lite);
	wattron(vm->lite, COLOR_PAIR(vm->winner + 1));
	mvwprintw(vm->lite, 1, 2, "Winner : %.20s", vm->player[vm->winner].name);
	wattroff(vm->lite, COLOR_PAIR(vm->winner + 1));
	wrefresh(vm->lite);
}

void	ft_print_name(t_vm *vm, int i, int *y)
{
	wattron(vm->menu, COLOR_PAIR(i + 1));
	mvwprintw(vm->menu, *y, 4, "%.20s", vm->player[i].name);
	wattroff(vm->menu, COLOR_PAIR(i + 1));
}

void	players_data(t_vm *vm, int *y)
{
	int		i;

	i = 0;
	while (i < vm->players_qnt)
	{
		*y += 4;
		mvwprintw(vm->menu, *y + 1, 4,
			"Last live : %16d", vm->player[i].last_live);
		mvwprintw(vm->menu, *y + 2, 4,
			"Lives in current period : %2d", vm->player[i].live_cur_period);
		ft_print_name(vm, i, y);
		i++;
	}
}

void	ft_create_menu(t_vm *vm)
{
	int		y;

	y = 1;
	werase(vm->menu);
	wattron(vm->menu, A_BOLD);
	mvwprintw(vm->menu, 1, 2, "** RUNNING **   Speed : %.*s",
		(SLOWEST_SPEED - vm->speed) / SPEED_DELTA, "|||||||||");
	mvwprintw(vm->menu, 2, 2, "Cycle  : %21d", vm->cycle);
	mvwprintw(vm->menu, 3, 2, "Processes  : %17d", vm->proceses_live);
	players_data(vm, &y);
	mvwprintw(vm->menu, y + 4, 2, "Cycle to die  : %7d :%5d",
		vm->period, vm->cycle_to_die);
	mvwprintw(vm->menu, y + 5, 2, "Live in period  : %5d :%5d",
		vm->nbr_live, NBR_LIVE);
}
