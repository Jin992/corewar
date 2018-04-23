/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:26:15 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 14:33:37 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_free_str_arr(char **tab)
{
	size_t i;

	i = 0;
	if (tab == 0)
		return (tab);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = 0;
	return (0);
}
