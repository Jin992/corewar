/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:26 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 17:42:27 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

#define MASK1 49280
#define MASK2 14712960
#define MASK3 4034953344

static int		count_bits(unsigned int c)
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

static size_t	two_bytes(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	out;
	unsigned char	add_to_mask[4];

	tmp = c;
	add_to_mask[1] = (tmp << 26) >> 26;
	add_to_mask[0] = ((tmp >> 6) << 27) >> 27;
	out = ((unsigned int)MASK1 >> 8) | add_to_mask[0];
	write(1, &out, 1);
	out = (((unsigned int)MASK1 << 24) >> 24) | add_to_mask[1];
	write(1, &out, 1);
	return (2);
}

static size_t	three_bytes(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	out;
	unsigned char	add_to_mask[4];

	tmp = c;
	add_to_mask[2] = (tmp << 26) >> 26;
	add_to_mask[1] = ((tmp >> 6) << 26) >> 26;
	add_to_mask[0] = ((tmp >> 12) << 28) >> 28;
	out = ((unsigned int)MASK2 >> 16) | add_to_mask[0];
	write(1, &out, 1);
	out = (((unsigned int)MASK2 << 16) >> 24) | add_to_mask[1];
	write(1, &out, 1);
	out = (((unsigned int)MASK2 << 24) >> 24) | add_to_mask[2];
	write(1, &out, 1);
	return (3);
}

static size_t	four_bytes(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	out;
	unsigned char	add_to_mask[4];

	tmp = c;
	add_to_mask[3] = (tmp << 26) >> 26;
	add_to_mask[2] = ((tmp >> 6) << 26) >> 26;
	add_to_mask[1] = ((tmp >> 12) << 26) >> 26;
	add_to_mask[0] = ((tmp >> 18) << 29) >> 29;
	out = ((unsigned int)MASK3 >> 24) | add_to_mask[0];
	write(1, &out, 1);
	out = (((unsigned int)MASK3 << 8) >> 24) | add_to_mask[1];
	write(1, &out, 1);
	out = (((unsigned int)MASK3 << 16) >> 24) | add_to_mask[2];
	write(1, &out, 1);
	out = (((unsigned int)MASK3 << 24) >> 24) | add_to_mask[3];
	write(1, &out, 1);
	return (4);
}

size_t			ft_putchar(unsigned int c)
{
	int		bits;
	size_t	res;

	res = 0;
	bits = count_bits(c);
	if (bits <= 7)
		res += write(1, &c, 1);
	else if (bits > 7 && MB_CUR_MAX == 1)
		res += write(1, &c, 1);
	else if (bits <= 11)
		res += two_bytes(c);
	else if (bits <= 16)
		res += three_bytes(c);
	else
		res += four_bytes(c);
	return (res);
}
