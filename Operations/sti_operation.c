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

int  check_register(t_VM *vm, t_process *cur)
{
	if ((if_good_reg_start(vm, cur)) == 0)
		return (0);
	if ((IS_REG_M(vm->memory[overla(cur->pc + 1)])))
	{
		if ((if_good_reg_midl(vm, cur, 3)) == 0)
			return (0);
		if ((if_good_reg_end(vm, cur, 4)) == 0)
			return (0);
	}
	else if ((if_good_reg_end(vm, cur, 5)) == 0)
		return (0);
	return (1);
}

void sti_operation(t_VM *vm, t_process *cur)
{
		u_int32_t  f2;
		u_int16_t  f3;
		int shift;
		int i;
		int pc;

		i = 0;
		pc = vm->memory[overla(cur->pc + 1)];
		int pos = vm->memory[(cur->pc + 2) % MEM_SIZE];
		if (IS_REG_S(vm->memory[overla(cur->pc + 1)]) && !IS_IND_M(vm->memory[overla(cur->pc + 1)]))
		{
			shift = 2;
			f2 = first_operand_2(vm, cur, &shift);
			f3 = second_operand_2(vm, cur, &shift);
			if (check_register(vm, cur))
			{
				while (i < REG_SIZE)
				{
					vm->memory[overla(cur->pc + get_idx_mod(f2 + f3) + i)] = cur->reg[pos - 1][i];
					vm->memory_color[(cur->pc + get_idx_mod(f2 + f3)) % MEM_SIZE + i] = cur->color;
					i++;
				}
			}
		}
		else if (IS_REG_S(vm->memory[overla(cur->pc + 1)]) && IS_IND_M(vm->memory[overla(cur->pc + 1)]))
		{
			shift = 3;
			f2 = get_4_bytes(vm, get_idx_mod(get_2_bytes(vm, overla(cur->pc + 3))));
			f3 = (second_operand_2(vm, cur, &shift));
			if (check_register(vm, cur))
			{
				while (i < REG_SIZE)
				{
					vm->memory[overla(cur->pc + get_idx_mod(f2 + f3) + i)] = cur->reg[pos - 1][i];
					vm->memory_color[overla(cur->pc + get_idx_mod(f2 + f3) + i)] = cur->color;
					i++;
				}
			}
		}
		move_pc_st(cur, vm, 2, 3, pc);
}