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

void	ft_create_map(t_VM *machine) // заполнение окна vm->main_field
{
	int y;
	int x;
	int i;
	int color;

	y = 0;
	i = 0;
	t_process *tmp = machine->processes;
	 wrefresh(machine->main_field);
	while (y++ < (MAX_FIELD_Y * 3))
	{
		x = 0;
		while (x < (MAX_FIELD_X * 3))
		{
			if (i < MEM_SIZE)
			{
				if (it_is_proces(machine, i) == 1)
				{
					color = 10 * machine->memory_color[i];
					if (color == 0)
						color = 100;
					wattron(machine->main_field, COLOR_PAIR(color));
					mvwprintw(machine->main_field, y, x, "%.2x", machine->memory[i]);
					wattroff(machine->main_field,COLOR_PAIR(color));
					mvwprintw(machine->main_field, y, x + 2, " ");
					i++;
				}
				else
				{
					wattron(machine->main_field, COLOR_PAIR(machine->memory_color[i]));
					mvwprintw(machine->main_field, y, x, "%.2x ", machine->memory[i]);
					wattroff(machine->main_field,COLOR_PAIR(machine->memory_color[i]));
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
		mvwprintw(vm->menu, *y, 2, "Player    : ");
		mvwprintw(vm->menu, *y, 9, "%d", vm->player[i].player_nbr);
		mvwprintw(vm->menu, *y + 1, 4, "Last live :");
		mvwprintw(vm->menu, *y + 1, 32, "%d", vm->player[i].last_live);
		mvwprintw(vm->menu, *y + 2, 4, "Lives in current period :");
		mvwprintw(vm->menu, *y + 2, 32, "%d", vm->player[i].live_cur_period);
		ft_print_name(vm, i, y);
		i++;
	}
}

void	ft_create_menu(t_VM *vm) // заполнение окна vm->menu
{
	int		y;

	y = 6;
	werase(vm->menu);
	wattron(vm->menu, A_BOLD);
	mvwprintw(vm->menu, 1, 2, "** RUNNING **");
	mvwprintw(vm->menu, 3, 2, "Cycles/second limit :");
	mvwprintw(vm->menu, 3, 32, ft_itoa(vm->cycle_limit));
	mvwprintw(vm->menu, 6, 2, "Cycle : 2");
	mvwprintw(vm->menu, 8, 2, "Processes : ");
	mvwprintw(vm->menu, 8, 32, ft_itoa(vm->proceses_live));
	players_data(vm, &y);
	mvwprintw(vm->menu, y + 4, 2, "CYCLE_TO_DIE :");
	mvwprintw(vm->menu, y + 4, 32, ft_itoa(vm->cycle_to_die));
	mvwprintw(vm->menu, y + 6, 2, "CYCLE_DELTA :"); //static
	mvwprintw(vm->menu, y + 6, 32, ft_itoa(CYCLE_DELTA));
	mvwprintw(vm->menu, y + 8, 2, "NBR_LIVE :                    21"); //static 
	mvwprintw(vm->menu, y + 10, 2, "MAX_CHECKS :                  10");
}

