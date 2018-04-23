/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:39:01 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/18 14:22:53 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	void	ft_lstfree(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(f) (t_list *elem))
{
	t_list	*lst_res;
	t_list	*lst_start;

	if (lst == NULL || f == NULL)
		return (NULL);
	lst_res = f(lst);
	if (lst_res == NULL)
		return (NULL);
	lst_start = lst_res;
	lst = lst->next;
	while (lst != NULL)
	{
		lst_res->next = f(lst);
		if (lst_res == NULL)
		{
			ft_lstdel(&lst_start, &ft_lstfree);
			break ;
		}
		lst_res = lst_res->next;
		lst = lst->next;
	}
	return (lst_start);
}
