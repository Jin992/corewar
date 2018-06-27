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

void	ft_create_window(t_vm *vm)
{
	ft_create_map(vm);
	ft_create_menu(vm);
	wrefresh(vm->menu);
	wrefresh(vm->main_field);
}

void	ft_create_frame_2(void)
{
	int i;

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
		mvwprintw(stdscr, 46, i, "%s", "*");
		mvwprintw(stdscr, 50, i, "%s", "*");
		i++;
	}
}

void	ft_create_frame(void)
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
	ft_create_frame_2();
	attroff(COLOR_PAIR(8));
	refresh();
	endwin();
}

void	ft_procesing_ncurses(t_vm *vm)
{
	ft_create_window(vm);
	get_key_2(vm);
	print_winner(vm);
	wrefresh(vm->menu);
	usleep(vm->speed);
}

void	procesing_step_by_step(t_vm *vm)
{
	if (vm->wait > 0)
		vm->wait--;
	if (vm->wait <= 0)
		ft_create_window(vm);
	get_key(vm);
	get_mouse(vm);
	print_winner(vm);
	wrefresh(vm->menu);
}
