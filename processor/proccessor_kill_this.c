/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccessor_kill_this.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:58:13 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/28 15:58:14 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"


void			proccessor_kill_this(t_process **begin_list)
{
	t_process *list;
	t_process *parent;
	t_process *tmp;

	list = *begin_list;
	parent = 0;
	tmp = 0;
	while (list)
	{
		tmp = list;
		if (tmp->im_alive == 0)
		{
			if (parent)
				parent->next = list->next;
			else
				*begin_list = list->next;
			free(list);	
		}
		else
		{
			tmp->im_alive = 0;
			parent = list;
		}
		list = tmp->next;
	}
}
