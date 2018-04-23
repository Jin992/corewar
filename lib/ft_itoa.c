/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:09:45 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 14:49:33 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	*arr_prep(int tmp_n, int min, int str_l, int n)
{
	char	*res;

	if (n == 0)
	{
		res = ft_strdup("0");
		if (res == NULL)
			return (NULL);
		return (res);
	}
	res = ft_strnew(str_l);
	if (res == NULL)
		return (NULL);
	while (tmp_n > 0)
	{
		res[str_l - 1] = tmp_n % 10 + '0';
		tmp_n = tmp_n / 10;
		str_l--;
	}
	if (min == 1)
		res[str_l - 1] = '-';
	return (res);
}

static char		*min_int(void)
{
	char *res;

	res = ft_strdup("-2147483648");
	if (res == NULL)
		return (NULL);
	return (res);
}

char			*ft_itoa(int n)
{
	size_t		str_l;
	int			temp_n;
	int			minus;

	temp_n = n;
	minus = 0;
	str_l = 0;
	if (temp_n == -2147483648)
		return (min_int());
	if (temp_n < 0)
	{
		minus = 1;
		temp_n *= -1;
		str_l++;
	}
	while (temp_n > 0)
	{
		temp_n = temp_n / 10;
		str_l++;
	}
	temp_n = n;
	if (temp_n < 0)
		temp_n = n * -1;
	return (arr_prep(temp_n, minus, str_l, n));
}
