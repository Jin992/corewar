/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccessor_kill_this.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:58:13 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/28 15:58:14 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	process_kill(t_process **alst, t_process *proc)
{
	t_process *cur;

	cur = *alst;
	if (cur && cur == proc)
	{
		if (cur->next)
			*alst = cur->next;
		ft_memdel((void**)&proc);
	}
	else
	{
		while (cur->next)
		{
			if (cur->next == proc)
			{
				cur->next = cur->next->next;
				ft_memdel((void**)&proc);
				return ;
			}
			cur = cur->next;
		}
	}
}

void	proccessor_kill_this(t_vm *vm)
{
	t_process *p;
	t_process *next;

	p = vm->processes;
	while (p)
	{
		next = p->next;
		if (p->im_alive == 0 || vm->cycle_to_die <= 0)
		{
			vm->proceses_live--;
			process_kill(&vm->processes, p);
		}
		else
			p->im_alive = 0;
		p = next;
	}
}
