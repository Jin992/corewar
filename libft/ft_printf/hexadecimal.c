/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:20:34 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 15:16:58 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t		get_res(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var_type == 0)
		tmp = (size_t)va_arg(*ap, unsigned int);
	if (list->data.var_type == 3)
		tmp = (size_t)((unsigned short)va_arg(*ap, unsigned int));
	if (list->data.var_type == 4)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 1)
		tmp = (size_t)((unsigned char)va_arg(*ap, unsigned int));
	if (list->data.var_type == 2)
		tmp = (size_t)va_arg(*ap, unsigned long long int);
	if (list->data.var_type == 5)
		tmp = (size_t)(size_t)va_arg(*ap, uintmax_t);
	if (list->data.var_type == 6)
		tmp = (size_t)va_arg(*ap, size_t);
	return (tmp);
}

static void			from_x_to_lx(t_lst *list)
{
	size_t i;

	i = 0;
	while (list->out.out[i] != '\0')
	{
		list->out.out[i] = (char)ft_toupper(list->out.out[i]);
		i++;
	}
}

int					digit_hex(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = get_res(list, ap);
	if (tmp == 0 && list->out.ch_zero)
	{
		if (!(list->out.out = ft_strdup("")))
			return (-1);
		list->flag.hash = 0;
		return (0);
	}
	if (!(list->out.out = ft_itoa_base((size_t)tmp, 16, 1)))
		return (-1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->flag.zero == 1 && list->data.prscn != 0)
		list->flag.zero = 0;
	if (list->flag.hash == 1)
		list->data.width -= 2;
	if (list->data.var == 'X')
		from_x_to_lx(list);
	set_width(list);
	set_precision(list);
	return (0);
}

int					print_hex(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	res += add_0x(list);
	if (list->data.prscn != 0)
		res += add_prcsn(list);
	if ((tmp = (int)ft_putstr(list->out.out)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
