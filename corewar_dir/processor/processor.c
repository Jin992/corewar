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

static	void (*g_operations[17])(t_vm *vm, t_process *cur) = { NULL,
	&live_operation, &ld_operation, &st_operation,
	&add_operation, &sub_operation, &and_operation,
	&or_operation, &xor_operation, &zjmp_operation,
	&ldi_operation, &sti_operation, &fork_operation,
	&lld_operation, &lldi_operation, &lfork_operation,
	&aff_operation };

static const int g_op_cycles[17] = { 0, 10, 5, 5, 10, 10, 6, 6, 6,
	20, 25, 25, 800, 10, 50, 1000, 2 };

static void	processor_move(t_vm *vm)
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
				processor_wrong_id(tmp);
		}
		processor_cycle(tmp, vm);
		if (tmp)
			tmp = tmp->next;
	}
}

void		processor_normal(t_vm *vm)
{
	while (vm->processes && vm->proceses_live > 0)
	{
		dump_memmory(vm);
		processor_move(vm);
		processor_check(vm);
		vm->cycle++;
	}
	winner(vm);
}

void		processor_e_mod(t_vm *vm)
{
	while (vm->processes && vm->proceses_live > 0)
	{
		if (vm->e_flag == vm->cycle)
		{
			vm->e_flag += vm->e_flag;
			print_mem(vm);
			sleep(1);
		}
		processor_move(vm);
		processor_check(vm);
		vm->cycle++;
	}
	winner(vm);
}

void		processor_visual(t_vm *vm)
{
	ft_start_ncurses(vm);
	ft_create_frame();
	ft_create_window(vm);
	mvwprintw(vm->menu, 1, 2, "** PAUSED **");
	while (vm->processes && vm->proceses_live > 0)
	{
		while ((vm->space == 1 || vm->cycle == 0)
			&& vm->processes && vm->cycle_to_die > 0)
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

void		processor_step_by_step(t_vm *vm)
{
	ft_start_ncurses(vm);
	ft_create_frame();
	mvwprintw(vm->menu, 1, 2, "** RUNNING **");
	while (vm->processes && vm->proceses_live > 0)
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
