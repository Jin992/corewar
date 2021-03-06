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

# define IS_DIR_S(x)((x & 0XC0) == 0X80)
# define IS_DIR_M(x)((x & 0X30) == 0X20)
# define IS_DIR_E(x)((x & 0X0C) == 0X08)
# define IS_IND_S(x)((x & 0XC0) == 0XC0)
# define IS_IND_M(x)((x & 0X30) == 0X30)
# define IS_IND_E(x)((x & 0X0C) == 0X0C)
# define IS_REG_S(x)((x & 0XC0) == 0X40)
# define IS_REG_M(x)((x & 0X30) == 0X10)
# define IS_REG_E(x)((x & 0X0C) == 0X04)
# include "vm.h"

typedef struct s_vm	t_vm;
typedef struct s_process	t_process;

void		live_operation(t_vm *vm, t_process *cur);
void		add_operation(t_vm *vm, t_process *cur);
void		fork_operation(t_vm *vm, t_process *cur);
void		aff_operation(t_vm *vm, t_process *cur);
void		and_operation(t_vm *vm, t_process *cur);
void		ld_operation(t_vm *vm, t_process *cur);
void		ldi_operation(t_vm *vm, t_process *cur);
void		lfork_operation(t_vm *vm, t_process *cur);
void		lld_operation(t_vm *vm, t_process *cur);
void		lldi_operation(t_vm *vm, t_process *cur);
void		or_operation(t_vm *vm, t_process *cur);
void		st_operation(t_vm *vm, t_process *cur);
void		sti_operation(t_vm *vm, t_process *cur);
void		sub_operation(t_vm *vm, t_process *cur);
void		xor_operation(t_vm *vm, t_process *cur);
void		zjmp_operation(t_vm *vm, t_process *cur);
int			get_idx_mod(short t_ind);
int			overla(int x);
int			get_reg(int x);
int			if_good_reg_midl(t_vm *vm, t_process *cur, int shift);
int			if_good_reg_start(t_vm *vm, t_process *cur);
int			if_good_reg_end(t_vm *vm, t_process *cur, int shift);
int			check_register(t_vm *vm, t_process *cur);
void		load_to_reg(t_process *cur, int reg_n, u_int32_t val);
void		move_pc
			(t_process *cur, t_vm *vm, int label, int params);
void		move_pc_st
			(t_process *cur, t_vm *vm, int label, int params);
u_int32_t	first_operand(t_vm *vm, t_process *cur, int *shift);
u_int32_t	second_operand(t_vm *vm, t_process *cur, int *shift);
int			first_operand_3(t_vm *vm, t_process *cur, int *shift);
int			second_operand_3(t_vm *vm, t_process *cur, int *shift);
int			first_operand_2(t_vm *vm, t_process *cur, int *shift);
int			second_operand_2(t_vm *vm, t_process *cur, int *shift);
u_int16_t	get_2_bytes(t_vm *vm, int pos);
u_int32_t	get_4_bytes(t_vm *vm, int pos);
int			check_c_octal_sti(u_int8_t val);
int			check_c_octal_or(u_int8_t val);
int			check_c_octal_ldi(u_int8_t val);

#endif
