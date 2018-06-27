/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:11:44 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/23 13:56:38 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	check_flag(const char *s, t_lst *list)
{
	if (*s == '-' || *s == '=' || *s == '#'
		|| *s == '0' || *s == ' ' || *s == '+')
	{
		if (*s == '-')
			list->flag.minus = 1;
		if (*s == '+')
			list->flag.plus = 1;
		if (*s == '#')
			list->flag.hash = 1;
		if (*s == ' ')
			list->flag.space = 1;
		if (*s == '0' && !ft_isdigit(*(s - 1)) && *(s - 1) != '.')
			list->flag.zero = 1;
		return (1);
	}
	return (0);
}

int	check_width(const char *s, t_lst *list, va_list *ap)
{
	size_t	i;
	char	*tmp;

	i = 0;
	star_width(list, ap, s, &i);
	if ((ft_atoi(s) > 0 || *(s - 1) != '.')
		&& list->data.width == 0 && list->data.prscn == 0)
	{
		if (ft_isdigit(s[i]) && s[i - 1] == '.')
			return (0);
		while (s[i] != '.' && ft_isdigit(s[i]))
			i++;
		if (i != 0 && list->data.width == 0)
		{
			if (!(tmp = ft_strsub(s, 0, i)))
				return (-1);
			list->data.width = (size_t)ft_atoi(tmp);
			free(tmp);
			return (1);
		}
	}
	return (0);
}

int	check_prcsn(const char *s, t_lst *list, va_list *ap)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if ((s[i] == '.' && (!ft_isdigit(s[i + 1]) && s[i + 1] != '*'))
		|| (s[i] == '.' && s[i + 1] == '0'))
	{
		list->out.ch_zero = 1;
		return (0);
	}
	star_prcn(list, ap, s, &i);
	if ((int)(list->data.prscn) < 0)
		list->data.prscn = 0;
	if (s[i] == '.' && ft_isdigit(s[i + 1]) && list->data.prscn == 0)
	{
		i++;
		while (ft_isdigit(s[i]))
			i++;
		if (!(tmp = ft_strsub(s, 1, i - 1)))
			return (-1);
		list->data.prscn = (size_t)ft_atoi(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

int	check_var_size(const char *s, t_lst *list)
{
	if (*s == 'h' && *(s + 1) == 'h')
		list->data.var_type = 1;
	if (*s == 'l' && *(s + 1) == 'l')
		list->data.var_type = 2;
	if ((*(s - 1) != 'h' && *s == 'h' && *(s + 1) != 'h'))
		list->data.var_type = 3;
	if (*(s - 1) != 'l' && *s == 'l' && *(s + 1) != 'l')
		list->data.var_type = 4;
	if (*s == 'j')
		list->data.var_type = 5;
	if (*s == 'z')
		list->data.var_type = 6;
	if (list->data.var_type != 0)
		return (1);
	return (0);
}

int	check_var(const char *s, t_lst *list)
{
	if (*s == 's' || *s == 'S' || *s == 'p' || *s == 'd' || *s == 'D'
		|| *s == 'i' || *s == 'o' || *s == 'O' || *s == 'u' || *s == 'U'
		|| *s == 'x' || *s == 'X' || *s == 'c' || *s == 'C' || *s == '%'
		|| *s == 'f' || *s == 'F')
	{
		list->data.var = *s;
		return (1);
	}
	else
	{
		if (wrong_var(s, list) == 1)
			return (2);
	}
	return (0);
}
