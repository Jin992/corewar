/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:15:31 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 13:55:55 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_copy;
	size_t	str_length;
	size_t	cnt;

	cnt = -1;
	str_length = ft_strlen(s1);
	str_copy = (char *)malloc(sizeof(char) * (str_length + 1));
	if (str_copy == NULL)
		return (NULL);
	while (++cnt < str_length)
		str_copy[cnt] = s1[cnt];
	str_copy[cnt] = '\0';
	return (str_copy);
}
