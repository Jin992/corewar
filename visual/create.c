/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakovet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:43:23 by ymakovet          #+#    #+#             */
/*   Updated: 2018/04/28 11:43:24 by ymakovet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	it_is_proces(t_VM *vm, int i)
{
	t_process *tmp;
	
	tmp = vm->processes;
	while (tmp)
	{
		if (tmp->pc == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_create_map(t_VM *vm)
{
	int y;
	int x;
	int i;
	int color;

	y = -1;
	i = 0;
	t_process *tmp = vm->processes;
	 wrefresh(vm->main_field);
	while (++y < (MAX_FIELD_Y * 3))
	{
		x = 0;
		while (x < (MAX_FIELD_X * 3))
		{
			if (i < MEM_SIZE)
			{
				if (it_is_proces(vm, i) == 1)
				{
					color = 10 * vm->memory_color[i];
					if (color == 0)
						color = 100;
					wattron(vm->main_field, COLOR_PAIR(color));
					mvwprintw(vm->main_field, y, x, "%.2x", vm->memory[i]);
					wattroff(vm->main_field,COLOR_PAIR(color));
					mvwprintw(vm->main_field, y, x + 2, " ");
					i++;
				}
				else
				{
					wattron(vm->main_field, COLOR_PAIR(vm->memory_color[i]));
					mvwprintw(vm->main_field, y, x, "%.2x", vm->memory[i]);
					wattroff(vm->main_field, COLOR_PAIR(vm->memory_color[i]));
					mvwprintw(vm->main_field, y, x + 2, " ");
					i++;
				}
			}
			x += 3;
		}
	}
}

// void	print_winner(t_VM *vm)
// {
// 	wattron(vm->litle, vm->winner);
// 	mvwprintw(vm->litle, *y, 17, "Winner : %.10s", vm->player[winner].name);
// 	wattroff(vm->litle, vm->winner);
// }

void	ft_print_name(t_VM *vm, int i, int *y)
{
	wattron(vm->menu, COLOR_PAIR(i + 1));
	mvwprintw(vm->menu, *y, 17, "%.10s", vm->player[i].name);
	wattroff(vm->menu, COLOR_PAIR(i + 1));
}

void	players_data(t_VM *vm, int *y)
{
	int		i;

	i = 0;
	while (i < vm->players_qnt)
	{
		*y += 4;
		mvwprintw(vm->menu, *y, 2, "Player : %17d", vm->player[i].player_nbr);
		mvwprintw(vm->menu, *y + 1, 4, "Last live : %16d", vm->player[i].last_live);
		mvwprintw(vm->menu, *y + 2, 4, "Lives in current period : %2d", vm->player[i].live_cur_period);
		ft_print_name(vm, i, y);
		i++;
	}
}

void	ft_create_menu(t_VM *vm)
{
	int		y;

	y = 1;
	werase(vm->menu);
	wattron(vm->menu, A_BOLD);
	mvwprintw(vm->menu, 1, 2, "** RUNNING **");
	// mvwprintw(vm->menu, 2, 2, "Cycles/second limit : %7d", vm->cycle_limit); // | | | | | | | | | | | | | |
	mvwprintw(vm->menu, 2, 2, "Cycle  : %21d", vm->cycle);
	// mvwprintw(vm->menu, 3, 2, "Processes  : %17d", vm->proceses_live);
	players_data(vm, &y);
	mvwprintw(vm->menu, y + 4, 2, "Cycle to die  : %7d :%5d", vm->period, vm->cycle_to_die);
	mvwprintw(vm->menu, y + 5, 2, "Live in period  : %5d :%5d", vm->nbr_live, NBR_LIVE);
}

