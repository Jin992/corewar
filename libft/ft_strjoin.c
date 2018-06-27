/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:39:41 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 13:56:15 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	res_len;
	char	*res;
	char	*res_start;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res_len = ft_strlen(s1) + ft_strlen(s2);
	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strnew(1));
	res = ft_strnew(res_len);
	res_start = res;
	if (res == NULL)
		return (NULL);
	if (*s1 != '\0')
		*res = *s1;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != '\0')
			*(++res) = *(++s1);
		if (*s1 == '\0' && *s2 != '\0')
			*(res++) = *(s2++);
	}
	return (res_start);
}
