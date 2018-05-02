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

void sti_operation(t_VM *vm, t_process *cur)
{
       u_int16_t  f2;
       u_int16_t  f3;
       int shift;
       int i;

       i = 0;
       if (IS_REG_S(vm->memory[OVERLAP(cur->pc + 1)]) && !IS_IND_M(vm->memory[OVERLAP(cur->pc + 1)]))
       {
              shift = 2;
              f2 = first_operand_2(vm, cur, &shift);
              f3 = second_operand_2(vm, cur, &shift);
//              printf("f2 = %.2x\n", f2);
//              printf("f3 = %.2x\n", f3);
              while (i < REG_SIZE)
              {
                     vm->memory[OVERLAP(cur->pc + (f2 + f3) % IDX_MOD + i)] = cur->reg[(vm->memory[OVERLAP(cur->pc + 2)]) - 1][i];
                     vm->memory_color[OVERLAP(cur->pc + (f2 + f3) % IDX_MOD + i)] = (u_int8_t)((cur->color * -1) + 2);
                     i++;

              }
             move_pc(cur, shift + 1);
       }
       else if (IS_REG_S(vm->memory[OVERLAP(cur->pc + 1)]) && IS_IND_M(vm->memory[OVERLAP(cur->pc + 1)]))
       {
              shift = 5;
              f2 = get_2_bytes(vm, vm->memory[OVERLAP(get_2_bytes(vm, OVERLAP(cur->pc + 3)))]);
              f3 = second_operand_2(vm, cur, &shift);
              while (i < REG_SIZE)
              {
                     vm->memory[OVERLAP(cur->pc + (f2 + f3) % IDX_MOD + i)] = cur->reg[vm->memory[OVERLAP(cur->pc + 2)]][i];
                     vm->memory_color[OVERLAP(cur->pc + (f2 + f3) % IDX_MOD + i)] = (u_int8_t)((cur->color * -1) + 2);
                     i++;
              }
              move_pc(cur, shift + 1);
       }
       else
              move_pc(cur, 1);
}

// усе по 2 байти

// sti	T_REG	T_REG | T_DIR | T_IND	T_REG | T_INDR	00001011	0x0B	store index	0	1	25	2

// "Значение T_REG (первый аргумент) записывается в ячейку, по адресу (текущая позиция PC плюс ((второй аргумент плюс третий аргумент) % IDX_MOD))
// - Если второй аргумент T_IND - то ясное дело, что вместо второго аргумента, в уровнение подставляются те 4 байта, которые мы берём из ячейки (T_IND % IDX_MOD)."