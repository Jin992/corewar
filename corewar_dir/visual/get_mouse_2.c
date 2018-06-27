/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:04:05 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 14:04:07 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_register_2(t_vm *vm)
{
	wattron(vm->help_menu, COLOR_PAIR((vm->print_reg->color)));
	mvwprintw(vm->help_menu, 1, 16,
		"Process carry status: %3d", vm->print_reg->carry);
	mvwprintw(vm->help_menu, 2, 16,
		"Process curent PC: %6d", vm->print_reg->pc);
	mvwprintw(vm->help_menu, 3, 16,
		"Process live status: %4d", vm->print_reg->im_alive);
}

void	print_register(t_vm *vm)
{
	int i;
	int j;
	int k;

	i = -1;
	if (vm->print_reg == NULL)
		return ;
	print_register_2(vm);
	while (++i < REG_NUMBER)
	{
		j = 0;
		k = 0;
		mvwprintw(vm->help_menu, 1 + i, 0 + j, "%d: ", i + 1);
		while (j < 12)
		{
			mvwprintw(vm->help_menu, 1 + i, 0 + j + 4, "%.2x ",
				vm->print_reg->reg[i][k]);
			k++;
			j += 3;
		}
	}
	wattroff(vm->help_menu, COLOR_PAIR((vm->print_reg->color)));
	wrefresh(vm->help_menu);
}

void	get_mouse(t_vm *vm)
{
	int			i;
	t_process	*tmp;
	MEVENT		mouse;

	i = 0;
	if ((getmouse(&mouse)) == OK)
	{
		tmp = vm->processes;
		while (tmp)
		{
			if (tmp->pc == (((mouse.y - 2) * 64) + (mouse.x / 3)) - 1)
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
			if_this_op(vm,
				vm->memory[(((mouse.y - 2) * 64) + (mouse.x / 3)) - 1]);
	}
}
