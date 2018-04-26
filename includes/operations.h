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

#define IS_DIR_S(x)(x >> 6 == 0X02 ) ? 1 : 0
#define IS_DIR_M(x)((((x << 2) & 0X80) >> 6) == 0X02) ? 1 : 0
#define IS_DIR_E(x)((((x << 4) & 0X80) >> 6) == 0X02) ? 1: 0
#define IS_IND_S(x)(x >> 6 == 0X03 ) ? 1 : 0
#define IS_IND_M(x)((((x << 2) & 0XC0) >> 6) == 0X03) ? 1 : 0
#define IS_IND_E(x)((((x << 4) & 0XC0) >> 6) == 0X03) ? 1: 0
#define IS_REG_S(x)(x >> 6 == 0X01) ? 1 : 0
#define IS_REG_M(x)((((x << 2) & 0X40) >> 6) == 0X01) ? 1 : 0
#define IS_REG_E(x)((((x << 4) & 0X40) >> 6) == 0X01) ? 1: 0

#include "vm.h"

typedef struct s_VM t_VM;
typedef struct s_process t_process;

void	live_operation(t_VM *machine, t_process *cur);
void	add_operation(t_VM *machine, t_process *cur);
void	fork_operation(t_VM *machine, t_process *cur);
void	aff_operation(t_VM *machine, t_process *cur);
void	and_operation(t_VM *machine, t_process *cur);
void 	ld_operation(t_VM *machine, t_process *cur);
void	ldi_operation(t_VM *machine, t_process *cur);
void	lfork_operation(t_VM *machine, t_process *cur);
void 	lld_operation(t_VM *machine, t_process *cur);
void	lldi_operation(t_VM *machine, t_process *cur);
void 	or_operation(t_VM *machine, t_process *cur);
void 	st_operation(t_VM *machine, t_process *cur);
void 	sti_operation(t_VM *machine, t_process *cur);
void 	sub_operation(t_VM *machine, t_process *cur);
void	xor_operation(t_VM *machine, t_process *cur);
void	zjmp_operation(t_VM *machine, t_process *cur);


#endif