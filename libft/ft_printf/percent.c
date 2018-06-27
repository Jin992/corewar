/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:50:36 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 14:06:29 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	percent(t_lst *list, va_list *ap)
{
	va_list b;

	va_copy(b, *ap);
	if (!(list->out.out = ft_strdup("%")))
		return (-1);
	list->data.prscn = 0;
	list->data.width -= 1;
	set_width(list);
	return (0);
}

int	print_percent(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if ((tmp = (int)ft_putstr(list->out.out)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}

int	error_input(t_lst *list, va_list *ap)
{
	va_list b;

	va_copy(b, *ap);
	list->data.width -= 2;
	set_width(list);
	return (0);
}

int	print_error(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if ((tmp = (int)ft_putchar((unsigned int)list->data.error)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
