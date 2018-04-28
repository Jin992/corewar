/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:34:39 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	lldi_operation(t_VM *machine, t_process *cur)
{
	if (IS_IND_S((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]) 
		&& (IS_REG_M((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]) 
		|| IS_DIR_M((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]))
		&& IS_REG_E((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]))
	{
		//pos = T_IND + PC << 4 bites + second 
		// pos + 2_rd read 4 bites 
		// write 3_rd
	}
	else if ((IS_REG_S((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]) ||
		IS_DIR_S((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]))
		&& (IS_REG_S((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]) ||
		IS_DIR_S((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]))
		&& IS_REG_E((u_int8_t)machine->memory[(cur->pc + 1) % MEM_SIZE]))
	{
		// ((((1 + 2) % IDX_MOD) + pc) % MEM_SIZE)
		//read 4 bite 
		// and write in 3_rd register
	}
	else
		cur->pc++;
}

