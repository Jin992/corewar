/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:52:44 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static	void (*g_operations[17])(t_VM *vm, t_process *cur) = { NULL,
	&live_operation, &ld_operation, &st_operation,
	&add_operation, &sub_operation, &and_operation,
	&or_operation, &xor_operation, &zjmp_operation,
	&ldi_operation, &sti_operation, &fork_operation,
	&lld_operation, &lldi_operation, &lfork_operation,
	&aff_operation };

static const int g_op_cycles[17] = { 0, 10, 5, 5, 10, 10, 6, 6, 6,
	20, 25, 25, 800, 10, 50, 1000, 2 };

static void	processor_move(t_VM *vm)
{
	t_process *tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (!(tmp->op))
		{
			if (vm->memory[tmp->pc] >= 1 && vm->memory[tmp->pc] <= 16)
			{
				tmp->op = g_operations[vm->memory[tmp->pc]];
				tmp->timer = g_op_cycles[vm->memory[tmp->pc]];
			}
			else
				processor_wrong__id(tmp);
		}
		else
			processor_cycle(tmp, vm);
		tmp = tmp->next;
	}
}

void		processor_normal(t_VM *vm)
{
	while (vm->processes)
	{
		dump_memmory(vm);
		processor_move(vm);
		processor_check(vm);
		vm->cycle++;
	}
	winner(vm);
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
void		processor_visual(t_VM *vm)
{
	ft_start_ncurses(vm);
	vm->space = 0;
	while (vm->processes)
	{
		while ((vm->space == 1 || vm->cycle == 0) && vm->processes)
		{
			dump_memmory(vm);
			if (vm->processes)
				ft_procesing_ncurses(vm);
			processor_move(vm);
			processor_check(vm);
			vm->cycle++;
		}
		get_key_2(vm);
	}
	del_win(vm);
}

void	processor_step_by_step(t_VM *vm)
{
	ft_start_ncurses(vm);
	ft_create_frame(vm);
	mvwprintw(vm->menu, 1, 2, "** RUNNING **");
	while (vm->processes)
	{
		dump_memmory(vm);
		if (vm->processes)
			procesing_step_by_step(vm);
		processor_move(vm);
		processor_check(vm);
		vm->cycle++;
	}
	del_win(vm);
}
