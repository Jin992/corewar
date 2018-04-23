/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_parts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:01:25 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 15:10:01 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	add_space(t_lst *list)
{
	int res;

	res = 0;
	if (list->flag.space == 1 && list->flag.plus != 1
		&& list->out.below_zero != 1)
	{
		list->flag.space = 0;
		res += ft_putstr(" ");
	}
	return (res);
}

int	add_0x(t_lst *list)
{
	int res;

	res = 0;
	if (list->flag.zero == 1 && list->flag.hash == 1
		&& list->data.var == 'x' && list->out.out[0] != '0')
		res += ft_putstr("0x");
	if (list->flag.zero == 1 && list->flag.hash == 1
		&& list->data.var == 'X' && list->out.out[0] != '0')
		res += ft_putstr("0X");
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->flag.hash == 1 && list->flag.zero == 0
		&& list->data.var == 'x' && list->out.out[0] != '0')
		res += ft_putstr("0x");
	if (list->flag.hash == 1 && list->flag.zero == 0
		&& list->data.var == 'X' && list->out.out[0] != '0')
		res += ft_putstr("0X");
	return (res);
}
