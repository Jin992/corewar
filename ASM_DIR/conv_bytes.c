/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:15:59 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/22 18:16:00 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						ft_is_that_op_code(char *op_code, int w)
{
	if (w == 1)
	{
		if (ft_strequ(op_code, "live") || ft_strequ(op_code, "lfork"))
			return (1);
		else if (ft_strequ(op_code, "fork") || ft_strequ(op_code, "zjmp"))
			return (1);
	}
	else
	{
		if (ft_strequ(op_code, "lfork") || ft_strequ(op_code, "lldi"))
			return (1);
		else if (ft_strequ(op_code, "fork") || ft_strequ(op_code, "sti"))
			return (1);
		else if (ft_strequ(op_code, "ldi") || ft_strequ(op_code, "zjmp"))
			return (1);
	}
	return (0);
}

unsigned int			ft_count_bytes(t_code *code, unsigned int num, char *w)
{
	while (code)
	{
		num += 2;
		if (ft_is_that_op_code(code->op_code, 1))
			num--;
		w = code->way;
		while (*w)
		{
			if (*w == 'r')
				num++;
			else if (*w == 'i')
				num += 2;
			else
			{
				if (ft_is_that_op_code(code->op_code, 2))
					num += 2;
				else
					num += 4;
			}
			w++;
		}
		code = code->next;
	}
	return (num);
}

unsigned int			reverse_b(unsigned int num, int size)
{
	unsigned int		reverse_n;
	int					u;

	reverse_n = 0;
	u = 0;
	while (u < size)
	{
		reverse_n |= ((num >> 8 * u) & UCHAR_MAX) << 8 * (size - 1 - u);
		u++;
	}
	return (reverse_n);
}

unsigned char			*conv_bytes(t_code *code, t_header *a, t_labels *l_list)
{
	unsigned int		bytes_num;
	unsigned char		*zer;
	unsigned int		num_chars;

	bytes_num = ft_count_bytes(code, 0, NULL);
	num_chars = bytes_num * 2 + bytes_num / 2;
	zer = (unsigned char *)malloc(sizeof(unsigned char) * (num_chars + 1));
	ft_bzero((void*)zer, num_chars + 1);
	a->prog_size = reverse_b(bytes_num, 4);
	a->magic = reverse_b(COREWAR_EXEC_MAGIC, 4);
	give_op_labels(l_list, code, (int)bytes_num);
	return (zer);
}
