/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:10:33 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/28 16:10:36 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void 	processor_check_2(t_VM *machine)
{
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

void 	processor_check(t_VM *machine)
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
				machine->proceses_live--;
				proccessor_kill_this(&machine->processes);
			}
			if (tmp)
			{
				tmp->im_alive = 0;
				tmp = tmp->next;
			}
		}
	}
}

void	winner(t_VM *machine)
{
	int i;

	i = -1;
	while (++i < machine->players_qnt)
		ft_printf("Player %d, exec size %d, \"%s\"\n", (i + 1) * -1, machine->player[i].exec_size ,machine->player[i].name);
	ft_printf("Game end in %d cycle\n", machine->cycle);
	ft_printf("Winner Player %d : \"%s\"\n", ((machine->winner + 1) * -1), machine->player[machine->winner].name);
}

void	processor_cycle(t_process *tmp, t_VM *machine)
{
	tmp->timer--;	
	if (tmp->timer == 0)
	{
		tmp->op(machine, tmp);
		tmp->op = NULL;
	}
}

void	processor_wrong__id(t_process *tmp)
{
	tmp->pc++;
	if (tmp->pc >= MEM_SIZE)
		tmp->pc = 0;
}