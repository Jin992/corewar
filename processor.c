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

//void 	die_processe(t_VM *machine)//Коли процес помирє
// Видаляємо його зі списку
//
//
//
void	move_procese(t_VM *machine)
{
	int i = 0;
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
		// getchar();
	}
}

void	processor(t_VM *machine)
{
	machine->time = 0;
	while (1)
	{
		move_procese(machine);
		// machine->time--;
		// print_memory(machine, 0);
	}
}