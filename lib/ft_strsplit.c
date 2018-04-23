/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:03:54 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 14:03:15 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		**ft_array_filler(char **res, char const *s, char c)
{
	char		**res_start;
	char const	*s_tmp;

	res_start = res;
	while (*s != '\0')
	{
		s_tmp = s;
		while (*s != c && *s != '\0')
			s++;
		if (s - s_tmp != 0)
		{
			*res = ft_strsub(s_tmp, 0, s - s_tmp);
			if (*res == NULL)
				return ((char **)ft_free_str_arr(res_start));
			res++;
		}
		if (*s == '\0')
			break ;
		s = s_tmp + (s - s_tmp) + 1;
	}
	return (res_start);
}

char			**ft_strsplit(char const *s, char c)
{
	char **res;

	res = NULL;
	if (s == NULL)
		return (NULL);
	if (ft_get_words(s, c) == 0)
		return (ft_new_str_arr(res, 0));
	res = ft_new_str_arr(res, ft_get_words(s, c));
	if (res == NULL)
		return (NULL);
	return (ft_array_filler(res, s, c));
}
