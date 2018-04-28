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

static void (*operations[17])(t_VM *machine, t_process *cur) = { NULL,
 			&live_operation, &ld_operation, &st_operation,
			&add_operation, &sub_operation, &and_operation,
			&or_operation, &xor_operation, &zjmp_operation,
			&ldi_operation, &sti_operation, &fork_operation,
			&lld_operation, &lldi_operation, &lfork_operation, 
			&aff_operation};

static const int op_cycles[17] = { 0, 10, 5, 5, 10, 10, 6, 6, 6,
	20, 25, 25, 800, 10, 50, 1000,2 };

static void	processor_move(t_VM *machine)
{
	t_process *tmp;

	tmp = machine->processes;
	while (tmp)
	{
		if (!(tmp->op))
		{
			if (machine->memory[tmp->pc] >= 1 && machine->memory[tmp->pc] <= 16)
			{
				tmp->op = operations[machine->memory[tmp->pc]];
				tmp->timer = op_cycles[machine->memory[tmp->pc]];
			}
			else
				processor_wrong__id(tmp);
		}
		else
			processor_cycle(tmp, machine);
		tmp = tmp->next;
	}
}

void	processor_normal(t_VM *machine)
{
	while (machine->processes)
	{
		processor_move(machine);
		processor_check(machine);
		machine->cycle++;
	}
	winner(machine);
}

void	processor_visual(t_VM *machine)
{
	int count;
	ft_start_ncurses(machine);
	
	count = 0;
	machine->space = 0;
	while (machine->processes)
	{
		while ((machine->space == 1 || count == 0) && machine->processes)
		{
			if (machine->processes)
				ft_procesing_ncurses(machine, count);
			processor_move(machine);
			processor_check(machine);
			usleep(100000);
			count++;
		}
		if (wgetch(machine->main_field) == 32)
		{
			if (machine->space == 0)
				machine->space = 1;
			else
				machine->space = 0;
		}
	}
}