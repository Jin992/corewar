/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_builder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:06:09 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/07 15:08:11 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_write_opc(t_instr *instr, int i)
{
	(i == 0) ? ft_strcpy(instr->op_code_v, "live") : 0;
	(i == 1) ? ft_strcpy(instr->op_code_v, "ld") : 0;
	(i == 2) ? ft_strcpy(instr->op_code_v, "st") : 0;
	(i == 3) ? ft_strcpy(instr->op_code_v, "add") : 0;
	(i == 4) ? ft_strcpy(instr->op_code_v, "sub") : 0;
	(i == 5) ? ft_strcpy(instr->op_code_v, "and") : 0;
	(i == 6) ? ft_strcpy(instr->op_code_v, "or") : 0;
	(i == 7) ? ft_strcpy(instr->op_code_v, "xor") : 0;
	(i == 8) ? ft_strcpy(instr->op_code_v, "zjmp") : 0;
	(i == 9) ? ft_strcpy(instr->op_code_v, "ldi") : 0;
	(i == 10) ? ft_strcpy(instr->op_code_v, "sti") : 0;
	(i == 11) ? ft_strcpy(instr->op_code_v, "fork") : 0;
	(i == 12) ? ft_strcpy(instr->op_code_v, "lld") : 0;
	(i == 13) ? ft_strcpy(instr->op_code_v, "lldi") : 0;
	(i == 14) ? ft_strcpy(instr->op_code_v, "lfork") : 0;
	(i == 15) ? ft_strcpy(instr->op_code_v, "aff") : 0;
}

void				ft_write_argum(t_instr *instr, int i)
{
	(i == 0) ? ft_strcpy(instr->argum, "d") : 0;
	(i == 1) ? ft_strcpy(instr->argum, "di r") : 0;
	(i == 2) ? ft_strcpy(instr->argum, "r ri") : 0;
	(i == 3) ? ft_strcpy(instr->argum, "r r r") : 0;
	(i == 4) ? ft_strcpy(instr->argum, "r r r") : 0;
	(i == 5) ? ft_strcpy(instr->argum, "rdi rdi r") : 0;
	(i == 6) ? ft_strcpy(instr->argum, "rdi rdi r") : 0;
	(i == 7) ? ft_strcpy(instr->argum, "rdi rdi r") : 0;
	(i == 8) ? ft_strcpy(instr->argum, "d") : 0;
	(i == 9) ? ft_strcpy(instr->argum, "rdi rd r") : 0;
	(i == 10) ? ft_strcpy(instr->argum, "r rdi rd") : 0;
	(i == 11) ? ft_strcpy(instr->argum, "d") : 0;
	(i == 12) ? ft_strcpy(instr->argum, "di r") : 0;
	(i == 13) ? ft_strcpy(instr->argum, "rdi rd r") : 0;
	(i == 14) ? ft_strcpy(instr->argum, "d") : 0;
	(i == 15) ? ft_strcpy(instr->argum, "r") : 0;
}

void				ft_build_valid(t_valid *valid)
{
	int				i;

	i = 0;
	ft_bzero((void*)valid->all_chars, 45);
	ft_strcpy(valid->all_chars,
		"abcdefghijklmnopqrstuvwxyz_0123456789#:;%, \t");
	valid->find_name = 0;
	valid->find_comment = 0;
	while (i < 16)
	{
		ft_bzero(valid->example_instr[i].op_code_v, 6);
		ft_bzero(valid->example_instr[i].argum, 13);
		ft_write_argum(&valid->example_instr[i], i);
		ft_write_opc(&valid->example_instr[i], i);
		i++;
	}
}
