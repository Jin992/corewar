/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:27:10 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 15:33:29 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (*((unsigned char *)s1) == '\0' && *((unsigned char *)s2) == '\0')
		return (0);
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i) != 0)
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}
