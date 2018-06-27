/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:07:54 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 13:08:10 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int		last_not_empty(t_vm *vm, int j)
{
	int i;

	i = 3;
	if (vm->empty[j] == 0)
	{
		while (i >= 0)
		{
			if (vm->empty[i] == 1)
			{
				vm->player[j] = vm->player[i];
				vm->empty[j] = 1;
				vm->empty[i] = 0;
				return (1);
			}
			i--;
		}
		return (0);
	}
	return (1);
}

void	load_players_to_memory(t_vm *vm)
{
	int i;
	int j;

	j = 0;
	while (j < vm->players_qnt)
	{
		if (last_not_empty(vm, j))
		{
			i = j * (MEM_SIZE / vm->players_qnt) - 1;
			processor_create(j + 1, i + 1, vm);
			vm->proceses_live++;
			while (++i < vm->player[j].exec_size +
				(j * (MEM_SIZE / vm->players_qnt)))
			{
				vm->memory[i] =
				(u_int8_t)vm->player[j].player_exec\
				[i - (j * (MEM_SIZE / vm->players_qnt))];
				vm->memory_color[i] = j + 1;
			}
		}
		else
			break ;
		j++;
	}
}
