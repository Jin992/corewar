/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:59:47 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 14:00:08 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	if (s == NULL || len == 0)
		return (ft_strnew(0));
	sub_str = ft_strnew(len);
	if (sub_str == NULL)
		return (NULL);
	while (i < len)
		sub_str[i++] = s[start++];
	return (sub_str);
}
