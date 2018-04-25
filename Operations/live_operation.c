/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:02 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/24 19:23:44 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	live_operation(t_VM *machine, t_process *cur)
{
	u_int16_t player;

	player = *(u_int16_t *)&machine->memory[cur->pc + 1];
	machine->player[player].last_live = machine->cycle;
	machine->player[player].live_cur_period++;
	ft_printf("live_operation Player: %d\n", player);
	cur->pc += 5;
}