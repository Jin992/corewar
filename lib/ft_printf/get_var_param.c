/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:11:06 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 11:39:30 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	w_input(unsigned *i, const char *format, t_lst **list, unsigned *p)
{
	if ((*list)->data.var == '0')
		*p = *i;
	else
		*p = *i + 1;
	if (format[*i + 1] != 0)
	{
		if (!((*list)->next = lst_init()))
			return (-1);
		(*list) = (*list)->next;
	}
	return (0);
}

static int	c_input(unsigned *i, const char *format, t_lst **list, unsigned *p)
{
	*p = *i + 1;
	if (format[(*i) + 1] != '\0')
	{
		if (!((*list)->next = lst_init()))
			return (-1);
		(*list) = (*list)->next;
	}
	return (0);
}

static int	check_cur_var(t_lst **list)
{
	if ((*list)->data.var == 's' || (*list)->data.var == 'S'
		|| (*list)->data.var == 'p' || (*list)->data.var == 'd'
		|| (*list)->data.var == 'D' || (*list)->data.var == 'i'
		|| (*list)->data.var == 'o' || (*list)->data.var == 'O'
		|| (*list)->data.var == 'u' || (*list)->data.var == 'U'
		|| (*list)->data.var == 'x' || (*list)->data.var == 'X'
		|| (*list)->data.var == 'c' || (*list)->data.var == 'C'
		|| (*list)->data.var == '%' || (*list)->data.var == 'f'
		|| (*list)->data.var == 'F')
		return (1);
	return (0);
}

static int	ch_block(unsigned *i, const char *format, t_lst **list, unsigned *p)
{
	int chck_var_res;

	if ((chck_var_res = check_var((format + *i), *list)) == 1)
	{
		if (check_cur_var(list))
		{
			if (c_input(i, format, list, p) == -1)
				return (-1);
			return (1);
		}
		else
		{
			if (w_input(i, format, list, p) == -1)
				return (-1);
			return (1);
		}
	}
	else if (chck_var_res == 2)
	{
		if (w_input(i, format, list, p) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int			get_param(unsigned *i, const char *f, t_lst **l, va_list *ap)
{
	int check_res;

	(*i)++;
	while (1)
	{
		check_flag((f + i[0]), *l);
		if (check_width((f + i[0]), *l, ap) == -1)
			return (-1);
		if (check_prcsn((f + i[0]), *l, ap) == -1)
			return (-1);
		check_var_size((f + i[0]), *l);
		check_res = ch_block(&i[0], f, l, &i[1]);
		if (check_res == 1)
			break ;
		else if (check_res == -1)
			return (-1);
		(*i)++;
	}
	return (0);
}
