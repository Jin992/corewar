/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:31:29 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 12:13:13 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)ptr)[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
