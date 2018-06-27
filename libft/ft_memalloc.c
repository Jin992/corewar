/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:13:52 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 15:27:44 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	if (size == 0)
		return (NULL);
	res = (unsigned char *)malloc(size);
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
