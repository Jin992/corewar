/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:16:36 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/04 11:50:30 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

static void		two_bytes(unsigned int c, int fd)
{
	unsigned int	tmp;
	unsigned char	out;
	unsigned char	add_to_mask[4];

	tmp = c;
	add_to_mask[1] = (tmp << 26) >> 26;
	add_to_mask[0] = ((tmp >> 6) << 27) >> 27;
	out = ((unsigned int)MASK1 >> 8) | add_to_mask[0];
	write(fd, &out, 1);
	out = (((unsigned int)MASK1 << 24) >> 24) | add_to_mask[1];
	write(fd, &out, 1);
}

static void		three_bytes(unsigned int c, int fd)
{
	unsigned int	tmp;
	unsigned char	out;
	unsigned char	add_to_mask[4];

	tmp = c;
	add_to_mask[3] = (tmp << 26) >> 26;
	add_to_mask[1] = ((tmp >> 6) << 26) >> 26;
	add_to_mask[0] = ((tmp >> 12) << 28) >> 28;
	out = ((unsigned int)MASK2 >> 16) | add_to_mask[0];
	write(fd, &out, 1);
	out = (((unsigned int)MASK2 << 16) >> 24) | add_to_mask[1];
	write(fd, &out, 1);
	out = (((unsigned int)MASK2 << 24) >> 24) | add_to_mask[2];
	write(fd, &out, 1);
}

static void		four_bytes(unsigned int c, int fd)
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
	write(fd, &out, 1);
	out = (((unsigned int)MASK3 << 8) >> 24) | add_to_mask[1];
	write(fd, &out, 1);
	out = (((unsigned int)MASK3 << 16) >> 24) | add_to_mask[2];
	write(fd, &out, 1);
	out = (((unsigned int)MASK3 << 24) >> 24) | add_to_mask[3];
	write(fd, &out, 1);
}

void			ft_putchar_fd(unsigned int c, int fd)
{
	int bits;

	bits = count_bits(c);
	if (bits <= 7)
		write(fd, &c, 1);
	else if (bits <= 11)
		two_bytes(c, fd);
	else if (bits <= 16)
		three_bytes(c, fd);
	else
		four_bytes(c, fd);
}
