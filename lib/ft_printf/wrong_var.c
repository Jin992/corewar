/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:40:09 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/23 14:12:31 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	wrong_var(const char *s, t_lst *list)
{
	if (ft_isalpha(*s) && !((*(s + 1) == 'h' && *s == 'h') || (*(s + 1) == 'l'
	&& *s == 'l') || *s == 'l' || *s == 'h' || *s == 'j' || *s == 'z'))
	{
		if (list->data.width != 0)
			list->data.w_crctn = 1;
		list->data.var = 'w';
		list->data.error = *s;
		return (1);
	}
	if (!ft_isalpha(*s) && !ft_isdigit(*s) && *s != '.')
	{
		if (!(*s == ' ' || *s == '-' || *s == '#' || *s == '0' || *s == '+'
			|| *s == '*'))
		{
			if ((list->data.width != 0 || list->data.prscn != 0)
				|| (list->data.width == 0 || list->data.prscn == 0))
				list->data.var = '0';
			return (1);
		}
	}
	return (0);
}
