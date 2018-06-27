/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:31:47 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 14:00:13 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*res;
	char const	*s_rev;

	if (s == NULL)
		return (NULL);
	s_rev = s + (ft_strlen(s) - 1);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strsub(s, 0, 1));
	while (*s_rev == ' ' || *s_rev == '\n' || *s_rev == '\t')
		s_rev--;
	res = ft_strsub(s, 0, s_rev - s + 1);
	return (res);
}
