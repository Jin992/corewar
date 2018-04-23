/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:48:55 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/23 14:10:04 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	star_width(t_lst *list, va_list *ap, const char *s, size_t *i)
{
	if ((*s == '*' && *(s - 1) != '.'))
	{
		list->data.width = va_arg(*ap, size_t);
		if (ft_isdigit(s[*i + 1]))
			list->data.width = 0;
	}
	if ((int)(list->data.width) < 0)
	{
		list->data.width = (size_t)((int)list->data.width * -1);
		list->flag.minus = 1;
	}
}

void	star_prcn(t_lst *list, va_list *ap, const char *s, size_t *i)
{
	if (s[*i] == '.' && s[*i + 1] == '*')
		if ((list->data.prscn = va_arg(*ap, size_t)) == 0)
			list->out.ch_zero = 1;
}
