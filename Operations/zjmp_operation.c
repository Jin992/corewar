/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:33:27 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	zjmp_operation(t_VM *vm, t_process *cur)
{
	if (cur->carry == 1)
		cur->pc = (cur->pc + get_2_bytes(vm, cur->pc + 1) % IDX_MOD) % MEM_SIZE;
	else if(cur->carry == 0)
		move_pc(cur, 3);
	else
		move_pc(cur, 1);
}