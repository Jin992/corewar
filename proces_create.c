/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:37:05 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/24 18:37:06 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"

void	proces_init(int color, int pc, t_process *new)
{
	new->color = color;
	new->pc = pc;
	new->timer = 0;
	new->carry = 0;
	new->next = NULL;
	new->prev = NULL;
	new->carry = 0;
	new->op = NULL;
}

void	proces_create(int color, int pc, t_VM *machine)
{
	t_process *new;
	t_process *tmp;

	new = (t_process*)malloc(sizeof(t_process) * 1);
	proces_init(color, pc, new);
	if (!(machine->processes))
		machine->processes = new;
	else
	{
		tmp = machine->processes;
		new->prev = tmp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	proces_init_clone(t_process *new, t_process *clone)
{
	new->pc = clone->pc;
	new->timer = clone->timer;
	new->color = clone->color;
	new->carry = clone->carry;
}

void	proces_clone(t_VM *machine, t_process *clone)
{
	t_process *new;
	t_process *tmp;

	new = (t_process*)malloc(sizeof(t_process) * 1);
	proces_init_clone(new, clone);
	if (!(machine->processes))
		machine->processes = new;
	else
	{
		tmp = machine->processes;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
}

void		kill_this_proccess(t_process **kill_me) //доробити
{
	t_process *die;

	if (!(kill_me))
		return ;
	else if (!((*kill_me)->prev) && !((*kill_me)->next))
	{
		ft_printf("1\n");
		free(*kill_me);
		*kill_me = NULL;
	}
	else if (!((*kill_me)->prev) && (*kill_me)->next)
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = NULL;
		ft_printf("2\n");
		free(die);
	}
	else if (!((*kill_me)->prev) && (*kill_me)->next)
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = NULL;
		ft_printf("3\n");
		free(die);
	}
	else
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = die->prev;
		free(die);
	}
}
