/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:26:04 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 15:04:05 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	get_res(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var_type == 0)
		tmp = (size_t)va_arg(*ap, int);
	if (list->data.var_type == 3)
		tmp = (size_t)((short)va_arg(*ap, int));
	if (list->data.var_type == 4)
		tmp = (size_t)va_arg(*ap, long int);
	if (list->data.var_type == 1)
		tmp = (size_t)((char)va_arg(*ap, int));
	if (list->data.var_type == 2)
		tmp = (size_t)va_arg(*ap, long long int);
	if (list->data.var_type == 5)
		tmp = (size_t)va_arg(*ap, intmax_t);
	if (list->data.var_type == 6)
		tmp = (size_t)va_arg(*ap, ssize_t);
	return (tmp);
}

static size_t	get_l_res(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var_type == 0)
		tmp = (size_t)va_arg(*ap, long int);
	if (list->data.var_type == 1)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 3)
		tmp = (size_t)va_arg(*ap, long int);
	if (list->data.var_type == 4)
		tmp = (size_t)va_arg(*ap, long int);
	if (list->data.var_type == 2)
		tmp = (size_t)va_arg(*ap, long long int);
	if (list->data.var_type == 5)
		tmp = (size_t)(size_t)va_arg(*ap, intmax_t);
	if (list->data.var_type == 6)
		tmp = (size_t)va_arg(*ap, ssize_t);
	return (tmp);
}

static int		dec_write(t_lst *list, size_t tmp)
{
	if (list->out.below_zero != 1 && list->flag.plus == 1)
		list->data.width -= 1;
	if (!(list->out.out = ft_itoa_base((size_t)tmp, 10, 0)))
		return (-1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->flag.zero == 1 && list->data.prscn != 0)
		list->flag.zero = 0;
	if (list->flag.space == 1
		&& list->flag.plus != 1 && list->out.below_zero != 1)
		list->data.width -= 1;
	set_width(list);
	set_precision(list);
	return (0);
}

int				digit_dec(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var == 'i' || list->data.var == 'd')
		tmp = get_res(list, ap);
	else if (list->data.var == 'D')
		tmp = get_l_res(list, ap);
	if (tmp == 0 && list->out.ch_zero)
	{
		if (!(list->out.out = ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((ssize_t)tmp < 0)
	{
		list->out.below_zero = 1;
		list->data.width -= 1;
		tmp *= -1;
	}
	if (dec_write(list, tmp) == -1)
		return (-1);
	return (0);
}

int				print_dec(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	res += add_space(list);
	if (list->flag.zero == 1 && list->out.below_zero == 1)
		res += ft_putstr("-");
	if (list->flag.plus == 1 && list->out.below_zero == 0
		&& list->flag.zero == 1)
		res += ft_putstr("+");
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->out.below_zero == 1 && list->flag.zero == 0)
		res += ft_putstr("-");
	if (list->flag.plus == 1 && list->out.below_zero == 0
		&& list->flag.zero == 0)
		res += ft_putstr("+");
	if (list->data.prscn != 0)
		res += add_prcsn(list);
	if ((tmp = (int)ft_putstr(list->out.out)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
