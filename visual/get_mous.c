/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:12:51 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/01 18:12:53 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_register(t_process *cur, t_VM *vm, int nbr)
{
	int i;
	int j;
	int k;

	i = -1;
	if (vm->print_reg == -1)
		return ;
	wattron(vm->help_menu, COLOR_PAIR((cur->color)));
	mvwprintw(vm->help_menu,  2, 0, "\t Process index %d", nbr);
	mvwprintw(vm->help_menu, 3 + i, 16, "Process carry status: %3d", cur->carry);
	mvwprintw(vm->help_menu, 4 + i, 16, "Process curent PC: %6d", cur->pc);
	mvwprintw(vm->help_menu, 5 + i, 16, "Process live status: %6d", cur->im_alive);
	while (++i < REG_NUMBER)
	{
		j = 0;
		k = 0;
		mvwprintw(vm->help_menu, 3 + i, 0 + j, "%d: ", i + 1);
		while (j < (REG_SIZE * 3))
		{
			mvwprintw(vm->help_menu, 3 + i, 0 + j + 4, "%.2x ", cur->reg[i][k]);
			k++;
			j += 3;
		}
	}
	wattroff(vm->help_menu, COLOR_PAIR((cur->color)));
}

void	get_mouse(t_VM *vm)
{
	int i;
	MEVENT mouse;
	
	i = 0;
	if ((getmouse(&mouse)) == OK)
	{
		
		t_process *tmp;
		tmp = vm->processes;
		// werase(vm->help_menu);
		while (tmp)
		{
			
			// mvwprintw(vm->help_menu,  2 + i, 0, "\t mouse = %d pc = %d", ((((mouse.y - 2) * 64) + (mouse.x / 3))) - 1, tmp->pc);
			if (tmp->pc == ((mouse.y - 2) * 64) + (mouse.x / 3) -1)
			{
				print_register(tmp, vm, i);
				break ;
			}
			i++;
			tmp = tmp->next;
		}
	}
	wrefresh(vm->help_menu);
}


void		get_key(t_VM *vm)
{
	char c;

	while (vm->wait <= 0)
	{
		c = wgetch(vm->main_field);
		if (c == 113)
			vm->wait = 1;
		else if (c == 119)
			vm->wait = 5;
		else if (c == 101)
			vm->wait = 10;
		else if (c == 97)
			vm->wait = 50;
		else if (c == 115)
			vm->wait = 100;
		else if (c == 100)
			vm->wait = 200;
		else if (c == 122)
			vm->wait = 300;
		else if (c == 120)
			vm->wait = 400;
		else if (c == 99)
			vm->wait = 500;
		get_mouse(vm);
	}
}

void		get_key_2(t_VM *vm)
{
	if (wgetch(vm->main_field) == 32)
	{
		if (vm->space == 0)
			vm->space = 1;
		else
		{
			vm->space = 0;
			mvwprintw(vm->menu, 1, 2, "** PAUSED **");
		}
	}
	if (vm->space == 0)
		get_mouse(vm);
}