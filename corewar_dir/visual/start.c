/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakovet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:52:25 by ymakovet          #+#    #+#             */
/*   Updated: 2018/04/28 11:52:26 by ymakovet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	ft_init_color(void)
{
	init_color(6, 411, 411, 411);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_CYAN);
	init_pair(40, COLOR_BLACK, COLOR_BLUE);
	init_pair(20, COLOR_BLACK, COLOR_GREEN);
	init_pair(30, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_YELLOW);
	init_pair(100, COLOR_BLACK, COLOR_WHITE);
}

void	ft_start_ncurses(t_vm *vm)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	start_color();
	ft_init_color();
	vm->main_field = newwin(64, 192, 2, 3);
	vm->menu = newwin(26, 37, 1, 197);
	vm->help_menu = newwin(17, 43, 28, 197);
	vm->help_menu_2 = newwin(10, 36, 51, 197);
	vm->lite = newwin(2, 30, 47, 197);
	keypad(vm->main_field, TRUE);
	nodelay(vm->main_field, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
}

void	print_info_players(t_vm *vm)
{
	int i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->players_qnt)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
		vm->player[i].exec_size, vm->player[i].name, vm->player[i].comment);
	}
}

void	print_mem(t_vm *vm)
{
	int i;
	int x;
	int y;
	int row_label;

	y = 0;
	i = 0;
	row_label = -64;
	print_info_players(vm);
	while (y++ < MAX_FIELD_Y)
	{
		x = 0;
		ft_printf("0x%.4x : ", row_label += MAX_FIELD_Y);
		while (x++ < MAX_FIELD_X)
			if (i < MEM_SIZE)
				ft_printf("%.2x ", vm->memory[i++]);
		ft_printf("\n");
	}
}

void	del_win(t_vm *vm)
{
	while ((wgetch(vm->main_field) != 32))
		;
	delwin(vm->menu);
	delwin(vm->help_menu);
	delwin(vm->main_field);
	delwin(stdscr);
	endwin();
}
