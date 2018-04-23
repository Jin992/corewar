/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:33:31 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 13:57:40 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	char_c(t_lst *list, va_list *ap)
{
	if (list->data.var_type == 4)
	{
		list->out.below_zero = (int)list->data.var_type;
		char_c_c(list, ap);
		return (0);
	}
	if (!(list->out.out = ft_strnew(1)))
		return (-1);
	list->out.out[0] = (char)va_arg(*ap, int);
	list->data.prscn = 0;
	list->data.width -= 1;
	set_width(list);
	return (0);
}

int	print_char(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->out.out[0] == 0)
		res += write(1, "\0", 1);
	else
	{
		if ((tmp = (int)ft_putstr(list->out.out)) == -1)
			return (-1);
		res += tmp;
	}
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
