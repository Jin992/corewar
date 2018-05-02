/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:32:57 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/24 20:23:09 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#define IS_DIR_S(x)((x & 0XC0) == 0X80)
#define IS_DIR_M(x)((x & 0X30) == 0X20)
#define IS_DIR_E(x)((x & 0X0C) == 0X08)
#define IS_IND_S(x)((x & 0XC0) == 0XC0)
#define IS_IND_M(x)((x & 0X30) == 0X30)
#define IS_IND_E(x)((x & 0X0C) == 0X0C)
#define IS_REG_S(x)((x & 0XC0) == 0X40)
#define IS_REG_M(x)((x & 0X30) == 0X10)
#define IS_REG_E(x)((x & 0X0C) == 0X04)
#include "vm.h"

typedef struct s_VM t_VM;
typedef struct s_process t_process;

void		live_operation(t_VM *vm, t_process *cur);
void		add_operation(t_VM *vm, t_process *cur);
void		fork_operation(t_VM *vm, t_process *cur);
void		aff_operation(t_VM *vm, t_process *cur);
void		and_operation(t_VM *vm, t_process *cur);
void 		ld_operation(t_VM *vm, t_process *cur);
void		ldi_operation(t_VM *vm, t_process *cur);
void		lfork_operation(t_VM *vm, t_process *cur);
void 		lld_operation(t_VM *vm, t_process *cur);
void		lldi_operation(t_VM *vm, t_process *cur);
void 		or_operation(t_VM *vm, t_process *cur);
void 		st_operation(t_VM *vm, t_process *cur);
void 		sti_operation(t_VM *vm, t_process *cur);
void 		sub_operation(t_VM *vm, t_process *cur);
void		xor_operation(t_VM *vm, t_process *cur);
void		zjmp_operation(t_VM *vm, t_process *cur);
u_int16_t	get_2_bytes(t_VM *vm, int pos);
u_int32_t 	get_4_bytes(t_VM *vm, int pos);
void		move_pc(t_process *cur, int shift);

u_int32_t 	first_operand(t_VM *vm, t_process *cur, int *shift);
void    	load_to_reg(t_process *cur,int reg_n, u_int32_t val);
u_int32_t 	second_operand(t_VM *vm, t_process *cur, int *shift);
u_int16_t 	first_operand_2(t_VM *vm, t_process *cur, int *shift);
u_int16_t 	second_operand_2(t_VM *vm, t_process *cur, int *shift);
int     overla(int x);
#endif