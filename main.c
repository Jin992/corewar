/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:49:49 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/30 16:49:52 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"

static void (*g_visual_vm[3])(t_VM *vm) = {
	&processor_normal,
	&processor_visual,
	&processor_step_by_step
};

static void	init_vm(t_VM *local, int argc)
{
	local->processes = NULL;
	local->proceses_live = 0;
	local->cycle_to_die = CYCLE_TO_DIE;
	local->period = CYCLE_TO_DIE;
	local->max_check = 1;
	local->visual = 0;
	local->players_qnt = 0;
	local->aff = 0;
	local->cycle = 0;
	local->dump = -1;
	ft_memset(local->empty, 0, 4);
	local->wait = 0;
	local->space = 0;
}

int main(int argc, char **argv)
{
	t_VM	local;

	init_vm(&local, argc);
	if (!(parse_flags(argc, argv, &local)))
		return (0);
	ft_memset(local.memory, 0, MEM_SIZE);
	ft_memset(local.memory_color, 0, MEM_SIZE);
	load_players_to_memory(&local);
	if (local.players_qnt == 0)
		return (usage());
	g_visual_vm[local.visual](&local);
	return (0);
}
