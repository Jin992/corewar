/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:53:54 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 13:59:15 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh_str;
	size_t	i;

	if (s == NULL || *s == '\0' || *f == NULL)
		return (NULL);
	i = 0;
	fresh_str = ft_strnew(ft_strlen(s));
	if (fresh_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		fresh_str[i] = f(s[i]);
		i++;
	}
	return (fresh_str);
}
