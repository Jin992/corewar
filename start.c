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

#include "includes/vm.h"

void	ft_init_color(void)
{
	init_color(6, 411, 411, 411);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_CYAN);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(20, COLOR_BLACK, COLOR_GREEN);
	init_pair(30, COLOR_BLACK, COLOR_RED);
	init_pair(40, COLOR_BLACK, COLOR_YELLOW);
	init_pair(100, COLOR_BLACK, COLOR_WHITE);

}

void	ft_start_ncurses(t_VM *vm)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
 	start_color();
 	ft_init_color();
 	vm->main_field = newwin(64, 192, 2, 3);
 	vm->menu = newwin(65, 56, 1, 197);
 	keypad(vm->main_field, TRUE);
	nodelay(vm->main_field, TRUE);
}
