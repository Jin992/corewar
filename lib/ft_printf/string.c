/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:08:00 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 14:54:53 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void				str_add_param(t_lst *list)
{
	list->data.out_len = ft_strlen(list->out.out);
	if (list->data.out_len < list->data.prscn)
		list->data.prscn = 0;
	if (list->data.prscn > 0)
		list->data.out_len = list->data.prscn;
	if (list->data.out_len > list->data.width)
		list->data.width = list->data.width - list->data.out_len;
	set_width(list);
	if (list->data.width != 0 && list->data.out_len > list->data.prscn
		&& list->data.prscn != 0)
		list->data.width += list->data.out_len - list->data.prscn;
}

int						char_string(t_lst *list, va_list *ap)
{
	char *tmp;

	if (list->data.var_type == 4)
		return (unicode_string(list, ap));
	tmp = va_arg(*ap, char *);
	if (tmp == NULL && list->out.ch_zero == 0)
	{
		if (!(list->out.out = ft_strdup("(null)")))
			return (-1);
	}
	else
	{
		if (tmp == NULL || list->out.ch_zero == 1)
		{
			list->out.out = ft_strnew(0);
			return (0);
		}
		if (!(list->out.out = ft_strdup(tmp)))
			return (-1);
	}
	str_add_param(list);
	return (0);
}

int						unicode_string(t_lst *list, va_list *ap)
{
	unsigned int *str;

	str = va_arg(*ap, unsigned int *);
	if (str == NULL)
	{
		if (!(list->out.out = ft_strdup("(null)")))
			return (-1);
		return (0);
	}
	if (!(list->out.out = uni_proc(str, list->data.prscn, list->out.ch_zero)))
		return (-1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->data.out_len < list->data.prscn)
		list->data.prscn = 0;
	if (list->data.prscn > 0)
		list->data.out_len = list->data.prscn;
	if (list->data.out_len > list->data.width)
		list->data.width = list->data.width - list->data.out_len;
	set_width(list);
	if (list->data.width != 0 && list->data.out_len > list->data.prscn
		&& list->data.prscn != 0)
		list->data.width += list->data.out_len - list->data.prscn;
	return (0);
}

static ssize_t			mini_writer(char *str, size_t n)
{
	size_t	i;
	size_t	res;

	if (str == NULL)
		return (-1);
	i = 0;
	res = 0;
	while (i < n)
	{
		res += write(1, &str[i], 1);
		i++;
	}
	return (res);
}

int						print_char_string(t_lst *list)
{
	int res;
	int tmp;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->data.out_len >= list->data.prscn && list->data.prscn != 0)
	{
		if ((tmp = (int)mini_writer(list->out.out, list->data.prscn)) == -1)
			return (-1);
		res += tmp;
	}
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
