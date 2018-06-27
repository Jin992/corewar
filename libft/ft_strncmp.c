/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:12:43 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/18 14:20:02 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (*s2 == '\0' || *s1 == '\0')
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	while (*(s1 + i) != '\0' && i < n)
		if (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i) == 0)
			i++;
		else
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	if (*(s1 + i) == '\0' && i < n)
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
