/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:25:11 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 13:56:00 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int res;

	res = 0;
	if (s1 != NULL || s2 != NULL)
	{
		if (s1 == NULL || s2 == NULL)
			return (res);
		if (ft_strcmp(s1, s2) == 0)
			res = 1;
		else
			res = 0;
	}
	else
		return (res);
	return (res);
}
