/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:34:09 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	fork_operation(t_VM *vm, t_process *cur) // processor_clone(t_VM *vm, t_process *clone)
{
    int position;

    position = (cur->pc + (REVERSE_2_BYTES(*(u_int16_t*)&vm->memory[cur->pc % MEM_SIZE + 1]))) % MEM_SIZE;
    printf("%d\n", cur->pc + (REVERSE_2_BYTES(*(u_int16_t*)&vm->memory[cur->pc % MEM_SIZE + 1])));
    processor_clone(vm, cur, position);
    cur->pc += 3;
}