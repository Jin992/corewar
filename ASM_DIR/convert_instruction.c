/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:17:27 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/24 13:17:28 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_dir(int *i_u, unsigned char *ins, t_code *code, t_labels *l)
{
	int		tmp;

	if (i_u[1] == 0)
	{
		if (code->dir_1[0] != ':')
			tmp = ft_atoi(code->dir_1);
		else
			tmp = ft_take_position(code, code->dir_1 + 1, l);
	}
	else if (i_u[1] == 1)
	{
		if (code->dir_2[0] != ':')
			tmp = ft_atoi(code->dir_2);
		else
			tmp = ft_take_position(code, code->dir_2 + 1, l);
	}
	else
	{
		if (code->dir_3[0] != ':')
			tmp = ft_atoi(code->dir_3);
		else
			tmp = ft_take_position(code, code->dir_3 + 1, l);
	}
	ft_direct_vc(code, tmp, ins, i_u[0]);
	return (code->label_size);
}

void		ft_indirect_val_crt(int tmp, unsigned char *instruction, int i)
{
	short	*ptr;

	tmp = reverse_b(tmp, 2);
	ptr = (short*)(instruction + i);
	*ptr = tmp;
}

int			ft_ind(int *i_u, unsigned char *ins, t_code *code, t_labels *l)
{
	short	tmp;

	if (i_u[1] == 0)
	{
		if (code->ind_1[0] != ':')
			tmp = ft_atoi(code->ind_1);
		else
			tmp = ft_take_position(code, code->ind_1 + 1, l);
	}
	else if (i_u[1] == 1)
	{
		if (code->ind_2[0] != ':')
			tmp = ft_atoi(code->ind_2);
		else
			tmp = ft_take_position(code, code->ind_2 + 1, l);
	}
	else
	{
		if (code->ind_3[0] != ':')
			tmp = ft_atoi(code->ind_3);
		else
			tmp = ft_take_position(code, code->ind_3 + 1, l);
	}
	ft_indirect_val_crt(tmp, ins, i_u[0]);
	return (2);
}

int			conv_arg(int i, unsigned char *ins, t_code *code, t_labels *l)
{
	int		i_u[2];
	int		rez;
	int		tmp;

	rez = 0;
	i_u[0] = i;
	i_u[1] = -1;
	while (code->way[++i_u[1]] != '\0')
	{
		if (code->way[i_u[1]] == 'r' && (rez += 1))
			ins[i_u[0]++] = code->reg[i_u[1]];
		else if (code->way[i_u[1]] == 'd')
		{
			tmp = ft_dir(i_u, ins, code, l);
			rez += tmp;
			i_u[0] += tmp;
		}
		else
		{
			tmp = ft_ind(i_u, ins, code, l);
			rez += tmp;
			i_u[0] += tmp;
		}
	}
	return (rez);
}

int			conv_ins(t_code *code, unsigned char *ins, t_labels *labels_l)
{
	int		i;

	i = 0;
	while (code)
	{
		if (code->op_code[0] != '\0')
		{
			ins[i] = code->op_num;
			i++;
			if (code->op_num != 1 && code->op_num != 9 && code->op_num != 12
				&& code->op_num != 15 && code->op_num != 0)
			{
				conv_codage(code);
				ins[i] = code->codage;
				i++;
			}
			i += conv_arg(i, ins, code, labels_l);
		}
		code = code->next;
	}
	return (i);
}
