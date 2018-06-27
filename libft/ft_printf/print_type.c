/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:55:34 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 19:07:43 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static ssize_t	signed_block(t_lst *l)
{
	ssize_t res;

	res = 0;
	if (l->data.var == 'i' || l->data.var == 'd' || l->data.var == 'D')
		res += print_dec(l);
	return (res);
}

static ssize_t	unsigned_block(t_lst *l)
{
	ssize_t res;

	res = 0;
	if (l->data.var == 'x' || l->data.var == 'X')
		res += print_hex(l);
	if (l->data.var == 'u' || l->data.var == 'U')
		res += print_unsigned(l);
	if (l->data.var == 'o' || l->data.var == 'O')
		res += print_oct(l);
	if (l->data.var == 'p')
		res += print_ptr(l);
	return (res);
}

static ssize_t	char_block(t_lst *l)
{
	ssize_t res;

	res = 0;
	if (l->data.var == 'C' || (l->data.var == 'c' && l->out.below_zero == 4))
		res += print_char_c(l);
	if (l->data.var == 'c' && l->out.below_zero == 0)
		res += print_char(l);
	if (l->data.var == 's' || l->data.var == 'S')
		res += print_char_string(l);
	return (res);
}

static ssize_t	float_block(t_lst *l)
{
	ssize_t res;

	res = 0;
	if (l->data.var == 'f' || l->data.var == 'F')
		res += print_float(l);
	return (res);
}

ssize_t			print_type(t_lst *l)
{
	ssize_t res;

	res = 0;
	res += signed_block(l);
	res += unsigned_block(l);
	res += char_block(l);
	res += float_block(l);
	if (l->data.var == '%')
		res += print_percent(l);
	if (l->data.var == 'w')
		res += print_error(l);
	if (res == -1)
		return (-1);
	return (res);
}
