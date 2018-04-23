/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:26:28 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/05 12:56:07 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t	ft_atoi(const char *str)
{
	ssize_t		res;
	int			minus_flag;

	minus_flag = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		minus_flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 7)) && minus_flag == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 8)) && minus_flag == -1)
			return (0);
	}
	return (res * minus_flag);
}
