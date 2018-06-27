/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:56:39 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 13:59:35 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	if (s1 != NULL || s2 != NULL)
	{
		if (s1 == NULL || s2 == NULL)
			return (res);
		if (ft_strncmp(s1, s2, n) == 0)
			res = 1;
		else
			res = 0;
	}
	else
		return (res);
	return (res);
}
