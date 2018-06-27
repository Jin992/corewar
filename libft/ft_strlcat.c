/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:15:31 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/18 14:19:37 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t res;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	res = ft_strlen(dst) + ft_strlen(src);
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dlen < size - 1)
	{
		dst[dlen] = *src;
		dlen++;
		src++;
	}
	if (dst[dlen] != '\0')
		dst[dlen] = '\0';
	return (res);
}
