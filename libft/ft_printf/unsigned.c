/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:29:08 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 13:54:37 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	get_res(t_lst *list, va_list *ap)
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

static size_t	get_l_res(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var_type == 0)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 1)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 4)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 3)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 2)
		tmp = (size_t)va_arg(*ap, unsigned long long int);
	if (list->data.var_type == 5)
		tmp = (size_t)(size_t)va_arg(*ap, uintmax_t);
	if (list->data.var_type == 6)
		tmp = (size_t)va_arg(*ap, size_t);
	return (tmp);
}

int				digit_unsigned(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var == 'u')
		tmp = get_res(list, ap);
	else if (list->data.var == 'U')
		tmp = get_l_res(list, ap);
	if (tmp == 0 && list->out.ch_zero)
	{
		if (!(list->out.out = ft_strdup("")))
			return (-1);
		return (0);
	}
	if (!(list->out.out = ft_itoa_base((size_t)tmp, 10, 1)))
		return (-1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->flag.zero == 1 && list->data.prscn != 0)
		list->flag.zero = 0;
	set_width(list);
	set_precision(list);
	return (0);
}

int				print_unsigned(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->data.prscn != 0)
		res += add_prcsn(list);
	if ((tmp = (int)ft_putstr(list->out.out)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
