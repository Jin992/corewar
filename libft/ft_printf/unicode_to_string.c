/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:23:09 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 17:23:12 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define MASK1 49280
#define MASK2 14712960
#define MASK3 4034953344

static char		*two_bytes(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	add_to_mask[4];
	char			*res;

	tmp = c;
	if (!(res = ft_strnew(2)))
		return (NULL);
	add_to_mask[1] = (tmp << 26) >> 26;
	add_to_mask[0] = ((tmp >> 6) << 27) >> 27;
	res[0] = ((unsigned int)MASK1 >> 8) | add_to_mask[0];
	res[1] = (((unsigned int)MASK1 << 24) >> 24) | add_to_mask[1];
	return (res);
}

static char		*three_bytes(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	add_to_mask[4];
	char			*res;

	tmp = c;
	if (!(res = ft_strnew(3)))
		return (NULL);
	add_to_mask[2] = (tmp << 26) >> 26;
	add_to_mask[1] = ((tmp >> 6) << 26) >> 26;
	add_to_mask[0] = ((tmp >> 12) << 28) >> 28;
	res[0] = ((unsigned int)MASK2 >> 16) | add_to_mask[0];
	res[1] = (((unsigned int)MASK2 << 16) >> 24) | add_to_mask[1];
	res[2] = (((unsigned int)MASK2 << 24) >> 24) | add_to_mask[2];
	return (res);
}

static char		*four_bytes(unsigned int c)
{
	unsigned int	tmp;
	unsigned char	add_to_mask[4];
	char			*res;

	tmp = c;
	if (!(res = ft_strnew(4)))
		return (NULL);
	add_to_mask[3] = (tmp << 26) >> 26;
	add_to_mask[2] = ((tmp >> 6) << 26) >> 26;
	add_to_mask[1] = ((tmp >> 12) << 26) >> 26;
	add_to_mask[0] = ((tmp >> 18) << 29) >> 29;
	res[0] = ((unsigned int)MASK3 >> 24) | add_to_mask[0];
	res[1] = (((unsigned int)MASK3 << 8) >> 24) | add_to_mask[1];
	res[2] = (((unsigned int)MASK3 << 16) >> 24) | add_to_mask[2];
	res[3] = (((unsigned int)MASK3 << 24) >> 24) | add_to_mask[3];
	return (res);
}

static char		*unicode_to_string(unsigned int c)
{
	int		bits;
	char	*res;

	res = NULL;
	bits = count_bits(c);
	if (bits <= 7)
	{
		if (!(res = ft_strnew(1)))
			return (NULL);
		res[0] = (char)c;
	}
	else if (bits <= 11)
		res = two_bytes(c);
	else if (bits <= 16)
		res = three_bytes(c);
	else
		res = four_bytes(c);
	return (res);
}

char			*uni_proc(unsigned int *str, ssize_t precision, int zero)
{
	size_t	i;
	char	*res;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!(res = ft_strnew(0)))
		return (NULL);
	while (str[i] != 0)
	{
		if (precision > 0 || zero == 1)
			if ((precision -= count_bytes(str[i])) < 0)
				break ;
		if (!(tmp = unicode_to_string(str[i])))
			return (NULL);
		if (!(tmp2 = ft_strjoin(res, tmp)))
			return (NULL);
		free(res);
		res = tmp2;
		free(tmp);
		i++;
	}
	return (res);
}
