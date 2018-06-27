/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccessor_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:35:55 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 13:35:58 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			processor_cycle(t_process *tmp, t_vm *vm)
{
	if (--tmp->timer == 0)
	{
		if (tmp->op)
			tmp->op(vm, tmp);
		tmp->op = NULL;
	}
}

void			processor_wrong_id(t_process *tmp)
{
	tmp->pc++;
	if (tmp->pc >= MEM_SIZE)
		tmp->pc = 0;
}

void			dump_memmory(t_vm *vm)
{
	if (vm->dump >= 0 && vm->cycle == vm->dump && vm->visual == 1)
	{
		del_win(vm);
		exit(1);
	}
	else if (vm->dump >= 0 && vm->cycle == vm->dump)
	{
		print_mem(vm);
		exit(1);
	}
}
