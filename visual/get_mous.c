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

void	print_register(t_VM *vm)
{
	int i;
	int j;
	int k;

	i = -1;
	if (vm->print_reg == NULL)
		return ;
	wattron(vm->help_menu, COLOR_PAIR((vm->print_reg->color)));
	mvwprintw(vm->help_menu, 1, 16, "Process carry status: %3d", vm->print_reg->carry);
	mvwprintw(vm->help_menu, 2, 16, "Process curent PC: %6d", vm->print_reg->pc);
	mvwprintw(vm->help_menu, 3, 16, "Process live status: %4d", vm->print_reg->im_alive);
	while (++i < REG_NUMBER)
	{
		j = 0;
		k = 0;
		mvwprintw(vm->help_menu, 1 + i, 0 + j, "%d: ", i + 1);
		while (j < (REG_SIZE * 3))
		{
			mvwprintw(vm->help_menu, 1 + i, 0 + j + 4, "%.2x ", vm->print_reg->reg[i][k]);
			k++;
			j += 3;
		}
	}
	wattroff(vm->help_menu, COLOR_PAIR((vm->print_reg->color)));
	wrefresh(vm->help_menu);
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
		while (tmp)
		{
			if (tmp->pc == (((mouse.y - 2) * 64) + (mouse.x / 3)) -1)
			{
				vm->print_reg = tmp;
				mouse.y = 10000;
				mouse.x = 10000;
				break ;
			}
			i++;
			tmp = tmp->next;
		}
		if (mouse.y != 10000)
			if_this_op(vm, vm->memory[(((mouse.y - 2) * 64) + (mouse.x / 3)) -1]);
	}
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
		print_register(vm);
	}
	print_register(vm);
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
	print_register(vm);
}