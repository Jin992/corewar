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

static void		processor_check_2(t_VM *vm)
{
	if (vm->nbr_live > NBR_LIVE || vm->max_check == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->nbr_live = 0;
		vm->max_check = 1;
	}
	else
		vm->max_check++;
	vm->nbr_live = 0;
	vm->period = vm->cycle_to_die;
}

static void		live_in_period_plaers(t_VM *vm)
{
	int i;

	i = -1;
	while (++i < vm->players_qnt)
		vm->player[i].live_cur_period = 0;
}

void			processor_check(t_VM *vm)
{
	vm->period--;
	if (vm->period <= 0)
	{
		proccessor_kill_this(&(vm->processes), vm);
		processor_check_2(vm);
		live_in_period_plaers(vm);
	}
}

void			winner(t_VM *vm)
{
	int i;

	i = -1;
	print_info_players(vm);
	ft_printf("Contestant %d, \"%s\", has won !\n",
		vm->winner + 1 , vm->player[vm->winner].name);
}

void			processor_cycle(t_process *tmp, t_VM *vm)
{
	if (--tmp->timer == 0)
	{
		if (tmp->op)
			tmp->op(vm, tmp);
		tmp->op = NULL;
	}
}

void			processor_wrong__id(t_process *tmp)
{
	tmp->pc++;
	if (tmp->pc == MEM_SIZE)
		tmp->pc = 0;
}

void		dump_memmory(t_VM *vm)
{

	if (vm->dump >= 0 && vm->cycle == vm->dump && vm->visual == 1)
	{
		del_win(vm);
		exit (1);
	}
	else if (vm->dump >= 0 && vm->cycle == vm->dump)
	{
		print_mem(vm);
		exit(1);
	}
}
