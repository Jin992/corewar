/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:56:42 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/25 14:04:01 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int		ft_power(int nb, size_t power)
{
	int power_mod;

	power_mod = nb;
	if ((int)power < 0)
		return (0);
	if ((int)power == 0)
		return (1);
	while ((int)power >= 2)
	{
		nb *= power_mod;
		power--;
	}
	return (nb);
}

static char		*float_part(t_lst *list, double n, char *int_part)
{
	char	*float_part;
	size_t	i;
	size_t	tmp;
	char	*res;

	i = 0;
	if (!(float_part = ft_strnew(list->data.prscn)))
		return (NULL);
	while (i < list->data.prscn)
	{
		n *= 10;
		tmp = (size_t)n;
		float_part[i] = (char)(tmp + '0');
		n -= tmp;
		i++;
	}
	if (!(res = ft_strjoin(int_part, float_part)))
		return (NULL);
	free(float_part);
	return (res);
}

static char		*float_to_string(double n, t_lst *list)
{
	char	*int_part;
	char	*res;
	size_t	tmp;

	if (list->data.prscn == 0)
		list->data.prscn = 6;
	n += 1.0 / ft_power(10, list->data.prscn + 1);
	tmp = (size_t)n;
	if (list->out.ch_zero == 1)
	{
		n -= tmp;
		if ((int)(n * 10) > 5)
			return (ft_itoa_base(tmp + 1, 10, 0));
		else
			return (ft_itoa_base(tmp, 10, 0));
	}
	if (!(int_part = ft_strjoin(ft_itoa_base(tmp, 10, 0), ".")))
		return (NULL);
	n -= tmp;
	if (!(res = float_part(list, n, int_part)))
		return (NULL);
	free(int_part);
	return (res);
}

int				digit_float(t_lst *list, va_list *ap)
{
	double res;

	res = va_arg(*ap, double);
	if (res == 0 && list->out.ch_zero)
	{
		if (!(list->out.out = ft_strdup("0")))
			return (-1);
		return (0);
	}
	if (res < 0)
	{
		list->out.below_zero = 1;
		list->data.width -= 1;
		res *= -1;
	}
	if (!(list->out.out = float_to_string(res, list)))
		return (-1);
	set_width(list);
	return (0);
}

int				print_float(t_lst *list)
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
	if ((tmp = (int)ft_putstr(list->out.out)) == -1)
		return (-1);
	res += tmp;
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
