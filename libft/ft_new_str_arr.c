/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:22:49 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 14:01:26 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_new_str_arr(char **str_arr, size_t size)
{
	str_arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (str_arr == NULL)
		return (NULL);
	str_arr[size] = 0;
	return (str_arr);
}
