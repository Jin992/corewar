/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:39:25 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/18 10:57:53 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if ((alst != NULL && del != NULL))
	{
		while (*alst != NULL)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
		}
		free(*alst);
		tmp = NULL;
		(*alst) = NULL;
	}
}
