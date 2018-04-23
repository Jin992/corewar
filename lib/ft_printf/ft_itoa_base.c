/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:45:55 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 15:47:17 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		arr_writer(size_t value, size_t base, size_t *i, char *res)
{
	char *arr;

	arr = "0123456789abcdef";
	if (value >= base)
		arr_writer(value / base, base, i, res);
	res[*i] = arr[value % base];
	*i += 1;
}

char			*ft_itoa_base(size_t value, int base, int u)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = ft_strnew(35)))
		return (NULL);
	if (base == 10 && !u)
	{
		if ((ssize_t)value < 0)
			value = (size_t)((ssize_t)value * -1);
	}
	arr_writer(value, (size_t)base, &i, res);
	return (res);
}


/*char			*ft_itoa_base(size_t value, int base, int u)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = ft_strnew(35)))
		return (NULL);
	if (base == 10 && !u)
	{
		if ((ssize_t)value < 0)
			value = (size_t)((ssize_t)value * -1);
	}
	arr_writer(value, (size_t)base, &i, res);
	return (res);
}*/