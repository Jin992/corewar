/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:28:27 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/17 14:53:46 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char *ptr_big;
	const char *ptr_little;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len != 0)
	{
		ptr_big = big;
		ptr_little = little;
		while (*big == *little && *little != '\0' && len--)
		{
			big++;
			little++;
		}
		if (*little == '\0')
			return ((char *)ptr_big);
		else
			len = len + (big - ptr_big - 1);
		little = ptr_little;
		big = ptr_big;
		big++;
	}
	return (NULL);
}
