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

int	it_is_proces(t_VM *vm, int i) // ваша функция
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

void	ft_create_map(t_VM *vm) // заполнение окна vm->main_field
{
	int y;
	int x;
	int i;
	int color;

	y = 0;
	i = 0;
	t_process *tmp = vm->processes;
	 wrefresh(vm->main_field);
	while (y++ < (MAX_FIELD_Y * 3) + 1)
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
					mvwprintw(vm->main_field, y, x, "%.2x ", vm->memory[i]);
					wattroff(vm->main_field,COLOR_PAIR(vm->memory_color[i]));
					i++;
				}
			}
			x += 3;
		}
	}
}

void	ft_print_name(t_VM *vm, int i, int *y)
{
	wattron(vm->menu, COLOR_PAIR(i + 1));
	mvwprintw(vm->menu, *y, 17, vm->player[i].name);
	wattroff(vm->menu, COLOR_PAIR(i + 1));
}

void	players_data(t_VM *vm, int *y)
{
	int		i;

	i = 0;
	while (i < vm->players_qnt)
	{
		*y += 4;
		mvwprintw(vm->menu, *y, 2, "Player : %15d", vm->player[i].player_nbr);
		mvwprintw(vm->menu, *y + 1, 4, "Last live : %15d", vm->player[i].last_live);
		mvwprintw(vm->menu, *y + 2, 4, "Lives in current period : %d", vm->player[i].live_cur_period);
		ft_print_name(vm, i, y);
		i++;
	}
}

void	ft_create_menu(t_VM *vm) // заполнение окна vm->menu
{
	int		y;

	y = 2;
	werase(vm->menu);
	wattron(vm->menu, A_BOLD);
	mvwprintw(vm->menu, 1, 2, "** RUNNING **");
	mvwprintw(vm->menu, 2, 2, "Cycles/second limit : %7d", vm->cycle_limit);
	mvwprintw(vm->menu, 3, 2, "Cycle : %21d", vm->cycle);
	mvwprintw(vm->menu, 4, 2, "Processes : %17d", vm->proceses_live);
	players_data(vm, &y);
	// mvwprintw(vm->menu, y + 4, 2, "CYCLE_TO_DIE : %d", vm->cycle_to_die);
	mvwprintw(vm->menu, y + 5, 2, "CYCLE_DELTA : %16d", CYCLE_DELTA);
	mvwprintw(vm->menu, y + 6, 2, "NBR_LIVE : %19d", NBR_LIVE );
	mvwprintw(vm->menu, y + 7, 2, "MAX_CHECKS : %17d", vm->period);
	mvwprintw(vm->menu, 30, 2, "    cycle - ");
	mvwprintw(vm->menu, 30, 17, "%d", vm->cycle);
}

