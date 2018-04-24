/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:52:44 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/24 19:52:45 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void (*operations[16])() = {&add_operation, 
		&aff_operation, &and_operation,
		&fork_operation, &ld_operation, &ldi_operation, 
		&lfork_operation, &live_operation, &lld_operation,
		&lldi_operation, &or_operation, &st_operation,
		&sti_operation, &sub_operation, &xor_operation, 
		&zjmp_operation};

static int op_cycles[16] = { 10, 5, 5, 10, 10, 6, 6, 6, 
	20, 25, 25, 800, 10, 50, 1000,2 };

void	move_procese(t_VM *machine)
{
	t_process *tmp;
	tmp = machine->processes;
	while (tmp)
	{
		if (tmp->timer == 0)
		{
			ft_printf("%.2x\n", machine->memory[tmp->pc]);
			if (machine->memory[tmp->pc] >= 1 && machine->memory[tmp->pc] <= 16)
				tmp->op = operations[machine->memory[tmp->pc]];
			tmp->timer = op_cycles[machine->memory[tmp->pc]];
		}
		else
			tmp->timer--;
		if (tmp->timer == 0)
			tmp->op();
		tmp = tmp->next;
	}
}

void	processor(t_VM *machine)
{
	machine->time = 0;
	while (machine->time + MEM_SIZE)
	{
		move_procese(machine);
		machine->time--;
	}
	ft_printf("\n");
}