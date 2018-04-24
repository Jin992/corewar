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
#define IS_IND
#define IS_REG

#include "lib/includes/libft.h"
#include "vm.h"

void	add_operation(t_VM *machine, t_process *cur);
void	aff_operation();
void	and_operation();
void	fork_operation();
void 	ld_operation();
void	ldi_operation();
void	lfork_operation();
void	live_operation(t_VM *machine, t_process *cur);
void 	lld_operation();
void	lldi_operation();
void 	or_operation();
void 	st_operation();
void 	sti_operation();
void 	sub_operation();
void	xor_operation();
void	zjmp_operation();

#endif