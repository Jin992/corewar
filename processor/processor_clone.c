/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_clone.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:59:23 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/28 15:59:24 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		processor_reg_copy(t_process *new, t_process *clone)
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

static void		processor_clone_init(t_process *new, t_process *clone, int pc)
{
	new->pc = pc;
	new->timer = 0;
	new->op = NULL;
	new->color = clone->color;
	new->carry = clone->carry;
	new->im_alive = clone->im_alive;
	new->next = NULL;
	processor_reg_copy(new, clone);
}

void			processor_clone(t_VM *vm, t_process *clone, int pc)
{
	t_process *new;
	t_process *tmp;

	new = (t_process*)malloc(sizeof(t_process) * 1);
	processor_clone_init(new, clone, pc);
    vm->proceses_live++;
	if (!(vm->processes))
		vm->processes = new;
	else
	{
		if (new)
		{
			new->next = vm->processes;
			vm->processes = new;
		}
	}
}
