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

#include "../includes/vm.h"

void	ft_create_window(t_VM *vm)
{
	wrefresh(vm->main_field);
	ft_create_map(vm);
	ft_create_menu(vm);
	wrefresh(vm->menu);
}

void	ft_create_frame(t_VM *vm)
{
	int i;
 
	i = 0;
	attron(COLOR_PAIR(8));
	i = 67;
	while (i >= 0)
	{	
		mvwprintw(stdscr, i, 0, "%s", "*");
		mvwprintw(stdscr, i, 241, "%s", "*");
		mvwprintw(stdscr, i, 196, "%s", "*");
		i--;
	}
	i = 240;
	while (i >= 0)
	{
		mvwprintw(stdscr, 0, i, "%s", "*");
		mvwprintw(stdscr, 67, i, "%s", "*");
		i--;
	}
	i = 197;
	while (i < 241)
	{
		mvwprintw(stdscr, 27, i, "%s", "*");
		i++;
	}
	attroff(COLOR_PAIR(8));
	refresh();
	endwin();
}


void	ft_procesing_ncurses(t_VM *vm)
{
	ft_create_window(vm);
	get_key_2(vm);
	wrefresh(vm->menu);
}

void	procesing_step_by_step(t_VM *vm)
{
	if (vm->wait > 0)
		vm->wait--;
	if (vm->wait <= 0)
		ft_create_window(vm);
	get_key(vm);
	get_mouse(vm);
	wrefresh(vm->menu);
}