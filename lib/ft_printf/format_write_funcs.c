/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_write_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:43:16 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 18:36:39 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_var(unsigned *i, const char *f, t_lst **list, va_list *ap)
{
	int get_var_res;

	if (((*list)->data.var == '0') && i[0] > 0 && i[1] - i[0] > 0)
	{
		if (!((*list)->out.out = ft_strsub(f, i[1], i[0] - i[1])))
			return (-1);
		(*list)->next = lst_init();
		if (!((*list) = (*list)->next))
			return (-1);
	}
	if ((get_var_res = get_param(i, f, list, ap)) == 0)
		return (0);
	else if (get_var_res == -1)
		return (-1);
	return (0);
}

static int		end(unsigned *i, const char *format, t_lst **list, unsigned *p)
{
	(*list)->next = lst_init();
	if (!((*list = (*list)->next)))
		return (-1);
	if (!((*list)->out.out = ft_strsub(format, *p, *i - *p)))
		return (-1);
	return (0);
}

static int		w_format(unsigned *ip, const char *f, t_lst **l)
{
	if (!((*l)->out.out = ft_strsub(f, ip[1], ip[0] - ip[1])))
		return (-1);
	(*l)->next = lst_init();
	if (!((*l) = (*l)->next))
		return (-1);
	return (0);
}

int				process_format(const char *format, t_lst *list, va_list *ap)
{
	unsigned int ip[2];

	ip[0] = 0;
	ip[1] = 0;
	while (format[ip[0]] != '\0')
	{
		if (format[ip[0]] == '%' && format[ip[0] + 1] == '\0')
		{
			if ((list->data.var == '0') && ip[0] > 0 && ip[1] - ip[0] != 0)
				if (w_format(ip, format, &list) == -1)
					return (-1);
			break ;
		}
		if (format[(ip[0])] == '%')
			if (get_var(ip, format, &list, ap) == -1)
				return (-1);
		ip[0]++;
	}
	if (format[ip[0]] == '\0')
		if (end(&ip[0], format, &list, &ip[1]) == -1)
			return (-1);
	return (0);
}
