/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:30:43 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/16 11:13:21 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_lstfind(t_list *list, void const *content)
{
	t_list *start;
	size_t elem_cnt;

	if (list == NULL || content == NULL)
		return (0);
	elem_cnt = 0;
	start = list;
	while (start != NULL)
	{
		elem_cnt++;
		if (memcmp(start->content, content, start->content_size) == 0)
			return (elem_cnt);
		start = start->next;
	}
	return (0);
}
