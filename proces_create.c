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

void	proces_create(int color, int pc, t_VM *machine)
{
	t_process *new;
	t_process *tmp;

	new = (t_process*)malloc(sizeof(t_process) * 1);
	new->color = color;
	new->pc = pc;
	new->timer = 0;
	new->carry = 0;
	new->next = NULL;
	if (!(machine->processes))
	{
		machine->processes = new;
	}
	else
	{
		tmp = machine->processes;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}