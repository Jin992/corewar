/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:53:46 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 13:48:54 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	digit_ptr(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = va_arg(*ap, unsigned long int);
	if (tmp == 0 && list->out.ch_zero)
	{
		if (!(list->out.out = ft_strdup("")))
			return (-1);
		return (0);
	}
	if (!(list->out.out = ft_itoa_base((size_t)tmp, 16, 1)))
		return (-1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->flag.zero == 1 && list->data.prscn != 0)
		list->flag.zero = 0;
	list->data.width -= 2;
	set_width(list);
	set_precision(list);
	return (0);
}

int	print_ptr(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->flag.zero == 1)
		res += ft_putstr("0x");
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->flag.zero == 0)
		res += ft_putstr("0x");
	if (list->data.prscn != 0)
		res += add_prcsn(list);
	if ((tmp = (int)ft_putstr(list->out.out)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
