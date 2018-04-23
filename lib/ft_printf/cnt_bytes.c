/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:14:27 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 17:15:10 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_bits(unsigned int c)
{
	int i;
	int tmp;

	i = 1;
	tmp = 0;
	while (i != 33)
	{
		if ((c & 1) == 1)
			tmp = i;
		c = c >> 1;
		i++;
	}
	return (tmp);
}

int		count_bytes(unsigned int c)
{
	int i;
	int tmp;

	i = 1;
	tmp = 0;
	while (i != 33)
	{
		if ((c & 1) == 1)
			tmp = i;
		c = c >> 1;
		i++;
	}
	if (tmp <= 7)
		return (1);
	else if (tmp <= 11)
		return (2);
	else if (tmp <= 16)
		return (3);
	else
		return (4);
	return (0);
}
