/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:50:09 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 15:16:01 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	while (i-- != 0)
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
	return (NULL);
}
