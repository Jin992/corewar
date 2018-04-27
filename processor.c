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

#include "includes/vm.h"
#include <stdio.h> 
static void (*operations[17])(t_VM *machine, t_process *cur) = { NULL,
 			&live_operation, &ld_operation, &st_operation,
			&add_operation, &sub_operation, &and_operation,
			&or_operation, &xor_operation, &zjmp_operation,
			&ldi_operation, &sti_operation, &fork_operation,
			&lld_operation, &lldi_operation, &lfork_operation, 
			&aff_operation};

static const int op_cycles[16] = { 10, 5, 5, 10, 10, 6, 6, 6, 
	20, 25, 25, 800, 10, 50, 1000,2 };

void	process_cycle(t_process *tmp, t_VM *machine)
{
	tmp->timer--;	
	if (tmp->timer == 0)
	{
		tmp->op(machine, tmp);
		tmp->op = NULL;
	}
}

void	wrong_process_id(t_process *tmp)
{
	tmp->pc++;
	if (tmp->pc >= MEM_SIZE)
		tmp->pc = 0;
}

void 	check_processe(t_VM *machine)
{
	t_process *tmp;

	tmp = machine->processes;
	machine->period--;
	if (machine->period <= 0)
	{
		while (tmp)
		{
			if (tmp->im_alive == 0)
			{
				mvwprintw(machine->menu, 10, 0,"DIE");
				wrefresh(machine->menu); // dell proces
				kill_this_proccess(&machine->processes);
			}
			if (tmp)
			{
				tmp->im_alive = 0;
				mvwprintw(machine->menu, 11, 0,"ALIVE");
				wrefresh(machine->menu);
				tmp = tmp->next;
			}
		}
		if (machine->nbr_live >= NBR_LIVE || machine->max_check == MAX_CHECKS)
		{
			machine->cycle_to_die -= CYCLE_DELTA;
			machine->nbr_live = 0;
			machine->max_check = 0;
		}
		else
			machine->max_check++;
		machine->nbr_live = 0;
		machine->period = machine->cycle_to_die;
	}
}

void	move_procese(t_VM *machine)
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
				wrong_process_id(tmp);
		}
		else
			process_cycle(tmp, machine);
		tmp = tmp->next;
	}
}

void	processor(t_VM *machine)
{
	init_ncurses(machine);

	while (machine->processes)
	{
		move_procese(machine);
		print_memory(machine, 0);
		check_processe(machine);
		mvwprintw(machine->menu, 25, 0, "period %d", machine->period);
		mvwprintw(machine->menu, 26, 0, "cycle to die %d", machine->cycle_to_die);
		mvwprintw(machine->menu, 27, 0, "nbr_live %d", machine->nbr_live);
		mvwprintw(machine->menu, 28, 0, "nbr cheks %d", machine->max_check);
		wrefresh(machine->menu);
		werase(machine->menu);
		machine->cycle++;
	}

	werase(machine->main_field);
	mvwprintw(machine->main_field, 0, 0, "Winner Player %d", machine->winner);
	wrefresh(machine->main_field);
	while (wgetch(machine->main_field) != 32)
	;
delwin(machine->main_field);
delwin(machine->menu);
}