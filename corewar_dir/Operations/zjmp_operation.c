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

void	zjmp_operation(t_vm *vm, t_process *cur)
{
	if (cur->carry == 1)
		cur->pc = (cur->pc + \
			get_idx_mod(get_2_bytes(vm, cur->pc + 1))) % MEM_SIZE;
	else if (cur->carry == 0)
		cur->pc = (cur->pc + 3) % MEM_SIZE;
}
