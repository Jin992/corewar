/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:17:08 by earteshc          #+#    #+#             */
/*   Updated: 2018/03/14 15:38:57 by jdoeeshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc_mod(void *ptr, size_t size, size_t old_size)
{
	void *tmp;

	tmp = NULL;
	if (old_size > 0)
	{
		if (!(tmp = malloc(old_size)))
			return (NULL);
		ft_memcpy(tmp, ptr, old_size);
		free(ptr);
	}
	if (!(ptr = ft_memalloc(size)))
		return (NULL);
	if (old_size > 0)
	{
		ft_memcpy(ptr, tmp, old_size);
		free(tmp);
	}
	return (ptr);
}
