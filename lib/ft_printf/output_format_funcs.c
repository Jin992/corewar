/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_format_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:34:21 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 16:34:24 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	set_width(t_lst *list)
{
	int o_len;
	int prsn_c;

	prsn_c = 0;
	if (list->data.width == 0)
		return (0);
	o_len = (int)(list->data.out_len - list->data.w_crctn);
	if ((int)list->data.width < o_len)
		return ((int)(list->data.width = 0));
	if (list->data.prscn != 0)
		prsn_c = (int)list->data.prscn - o_len;
	if (prsn_c < 0 || o_len < 0)
		prsn_c = 0;
	if ((int)list->data.width >= o_len)
	{
		if (list->flag.zero == 1 && list->flag.minus == 1)
			list->flag.zero = 0;
		if ((ssize_t)(list->data.width - o_len - prsn_c) < 0)
			list->data.width = 0;
		else
			list->data.width = list->data.width - o_len - prsn_c;
	}
	return (0);
}

int	set_precision(t_lst *list)
{
	size_t o_len;

	o_len = 0;
	if (list->data.prscn == 0)
		return (0);
	if (list->data.prscn > 0)
	{
		o_len = ft_strlen(list->out.out);
		if (list->data.prscn <= o_len)
			list->data.prscn = 0;
		else
			list->data.prscn = list->data.prscn - o_len;
	}
	return (0);
}

int	add_width(t_lst *list)
{
	size_t	i;
	int		res;
	char	c;

	i = 0;
	res = 0;
	if (list->flag.zero == 1)
		c = '0';
	else
		c = ' ';
	while (i < list->data.width)
	{
		res += write(1, &c, 1);
		i++;
	}
	return (res);
}

int	add_prcsn(t_lst *list)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (i < list->data.prscn)
	{
		res += write(1, "0", 1);
		i++;
	}
	return (res);
}
