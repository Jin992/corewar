/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:37:05 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"



void 	player_index_to_int8(int color, t_process *new)
{
	int			i;
	u_int8_t	bytes[4];

	i = -1;
    ft_bzero(new->reg, 4);
    ft_bzero(bytes, 4);
	color = (color + 1) * -1;
	bytes[0] = (color >> 24) & 0xFF;
	bytes[1] = (color >> 16) & 0xFF;
	bytes[2] = (color >> 8) & 0xFF;
	bytes[3] = color & 0xFF;
	while (++i < REG_SIZE)
		new->reg[0][i] = bytes[i];
    i = 0;
    while (++i < REG_NUMBER)
        ft_bzero(new->reg[i], REG_SIZE);
}

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
	new->im_alive = 0;
	player_index_to_int8(color, new);
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

void	reg_copy(t_process *new, t_process *clone)
{
	int i;
	int j;

	i = 0;
	while (i < REG_NUMBER)
	{
		j = -1;
		while (++j < REG_SIZE)
			new->reg[i][j] = clone->reg[i][j];
		i++;
	}
}

void	proces_init_clone(t_process *new, t_process *clone)
{
	new->pc = clone->pc;
	new->timer = clone->timer;
	new->color = clone->color;
	new->carry = clone->carry;
	reg_copy(new, clone);
	// new->im_alive->
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
		free(*kill_me);
		*kill_me = NULL;
	}
	else if (!((*kill_me)->prev) && (*kill_me)->next)
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = NULL;
		free(die);
	}
	else if (!((*kill_me)->prev) && (*kill_me)->next)
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = NULL;
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
