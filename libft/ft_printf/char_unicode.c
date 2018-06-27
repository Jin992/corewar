/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:37:18 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 14:41:31 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	char_c_c(t_lst *list, va_list *ap)
{
	va_list b;

	va_copy(b, *ap);
	list->data.var_type = va_arg(*ap, unsigned int);
	list->data.prscn = 0;
	list->data.width -= 1;
	set_width(list);
	return (0);
}

int	print_char_c(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->data.var_type == 0)
		res += write(1, "\0", 1);
	else
	{
		if ((tmp = (int)ft_putchar((unsigned)list->data.var_type)) == -1)
			return (-1);
		res += tmp;
	}
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
