/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instruction_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:08:42 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/09 11:08:43 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			conv_codage_r_d(t_code *code, int u)
{
	if (u == 0)
	{
		(code->way[u] == 'd') ? (code->codage |= FIRST) : 0;
		(code->way[u] == 'r') ? (code->codage |= SECOND) : 0;
		if (code->way[u] == 'i')
		{
			code->codage |= FIRST;
			code->codage |= SECOND;
		}
	}
	else if (u == 1)
	{
		(code->way[u] == 'd') ? (code->codage |= THIRD) : 0;
		(code->way[u] == 'r') ? (code->codage |= FOURTH) : 0;
		if (code->way[u] == 'i')
		{
			code->codage |= THIRD;
			code->codage |= FOURTH;
		}
	}
}

void			conv_codage(t_code *code)
{
	int			u;

	u = 0;
	code->codage = 0;
	while (code->way[u] != '\0')
	{
		if (u == 0 || u == 1)
			conv_codage_r_d(code, u);
		else
		{
			(code->way[u] == 'd') ? (code->codage |= FIFTH) : 0;
			(code->way[u] == 'r') ? (code->codage |= SIXTH) : 0;
			if (code->way[u] == 'i')
			{
				code->codage |= FIFTH;
				code->codage |= SIXTH;
			}
		}
		u++;
	}
}

char			*ft_good_dir(char *old_dir)
{
	char		*new_dir;
	int			i;

	i = 0;
	while (old_dir[i] != '\0')
	{
		if (old_dir[i] == ' ' || old_dir[i] == '\t' || old_dir[i] == '#')
			break ;
		i++;
	}
	new_dir = ft_strnew(i);
	ft_strncpy(new_dir, old_dir, i);
	return (new_dir);
}

int				ft_take_position(t_code *code, char *dir, t_labels *labels_list)
{
	char		*dd;

	dd = dir;
	dir = ft_good_dir(dd);
	while (labels_list)
	{
		if (ft_strequ(labels_list->label, dir))
		{
			free(dir);
			return (labels_list->opcode_position - code->opcode_position);
		}
		labels_list = labels_list->next;
	}
	free(dir);
	dir = ft_strdup(code->op_code);
	ft_error_exit(4, 0, 0, dir);
	return (0);
}

void			ft_direct_vc(t_code *code, int tmp, unsigned char *ins, int i)
{
	short		sht;
	int			*ptr;
	int			g;

	g = 4;
	if (code->label_size == 2)
	{
		sht = (short)tmp;
		tmp = sht;
		g = 2;
	}
	tmp = reverse_b(tmp, g);
	ptr = (int*)(ins + i);
	*ptr = tmp;
}
