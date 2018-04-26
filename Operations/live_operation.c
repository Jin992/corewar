/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:02 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	live_operation(t_VM *machine, t_process *cur)
{
	u_int16_t player;

	player = *(u_int16_t *)&machine->memory[cur->pc + 1];
	if (player < machine->players_qnt && player >= 0)
	{
		machine->player[player].last_live = machine->cycle;
		machine->player[player].live_cur_period++;
		machine->winner = player;
		cur->pc += 4;
	}
	else
		cur->pc++;
////	ft_printf("live_operation Player: %d\n", player);

}