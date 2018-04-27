/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:34:53 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	lfork_operation(t_VM *machine, t_process *cur)
{
    int position;

    position = (cur->pc + REVERSE_2_BYTES(*(u_int16_t*)&machine->memory[cur->pc % MEM_SIZE + 1])) % MEM_SIZE;
    proces_clone(machine, cur, position);
    cur->pc += 3;
}