/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakovet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:36:51 by ymakovet          #+#    #+#             */
/*   Updated: 2018/04/21 14:36:52 by ymakovet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_create_window(t_VM *vm) //
{
	wrefresh(vm->main_field);
	ft_create_map(vm);
	ft_create_menu(vm);
	wrefresh(vm->menu);
}

void	ft_create_frame(t_VM *vm) // создание рамочки stdscr
{
	char *mesg = "*";
	int row, col, i;
 
	row = 67;
	col = 253;
	i = 0;
	attron(COLOR_PAIR(8));
	i = row;
	while (i >= 0)
	{	
		mvwprintw(stdscr, i, 0, "%s", mesg);
		mvwprintw(stdscr, i, col, "%s", mesg);
		mvwprintw(stdscr, i, 196, "%s", mesg);
		i--;
	}
	i = col;
	while (i >= 0)
	{
		mvwprintw(stdscr, 0, i, "%s", mesg);
		mvwprintw(stdscr, row, i, "%s", mesg);
		i--;
	}
	attroff(COLOR_PAIR(8));
	refresh();
	endwin();
}

void	ft_procesing_ncurses(t_VM *vm, int count)
{
	if (count == 0)
	{
		ft_create_frame(vm);
		mvwprintw(vm->menu, 1, 2, "** PAUSED **");
	}
	ft_create_window(vm);
	mvwprintw(vm->menu, 30, 2, "    cycle - ");
	mvwprintw(vm->menu, 30, 17, "%d", count);
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
	wrefresh(vm->menu);
}
