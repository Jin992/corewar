/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:33:53 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:40:14 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

int 	overla(int x)
{
	return (x % MEM_SIZE);
}

int 	get_reg(int x)
{
	if (x >= 1 && x < 17)
		return (1);
	return (0);
}

void sti_operation(t_VM *vm, t_process *cur)
{
		u_int16_t  f2;
		u_int16_t  f3;
		int shift;
		int i;

		i = 0;
		int pos = vm->memory[(cur->pc + 2)];
		if (IS_REG_S(vm->memory[overla(cur->pc + 1)]) && !IS_IND_M(vm->memory[overla(cur->pc + 1)]))
		{
			shift = 2;
			f2 = first_operand_2(vm, cur, &shift);
			f3 = second_operand_2(vm, cur, &shift);
			if (get_reg((vm->memory[overla(cur->pc + 2)])))
				while (i < REG_SIZE)
				{
					vm->memory[(cur->pc + (f2 + f3) + i) % MEM_SIZE] = cur->reg[pos - 1][i];
					vm->memory_color[(cur->pc + (f2 + f3) + i) % MEM_SIZE] = cur->color;
					i++;
				}
			move_pc(cur, shift + 1);
		}
		else if (IS_REG_S(vm->memory[overla(cur->pc + 1)]) && IS_IND_M(vm->memory[overla(cur->pc + 1)]))
		{
			shift = 5;
			f2 = get_2_bytes(vm, vm->memory[overla(get_2_bytes(vm, overla(cur->pc + 3)))]);
			f3 = second_operand_2(vm, cur, &shift);
			while (i < REG_SIZE)
			{
				vm->memory[overla(cur->pc + (f2 + f3)+ i)] = cur->reg[vm->memory[cur->pc + 2] - 1][i];
				vm->memory_color[overla(cur->pc + (f2 + f3) + i)] = cur->color;
				i++;
			}
				move_pc(cur, shift + 1);
		}
		else
			  move_pc(cur, 1);
		
}