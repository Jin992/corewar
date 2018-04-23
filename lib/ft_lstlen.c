/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:50:22 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 11:12:27 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_lstlen(t_list *list)
{
	size_t cnt;

	cnt = 0;
	if (list == NULL)
		return (0);
	while (list->next != NULL)
	{
		cnt++;
		list = list->next;
	}
	cnt++;
	return (cnt);
}
