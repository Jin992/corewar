/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:57:41 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/22 18:28:01 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst		*lst_init(void)
{
	t_lst *list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	list->flag.plus = 0;
	list->flag.minus = 0;
	list->flag.zero = 0;
	list->flag.hash = 0;
	list->data.out_len = 0;
	list->flag.space = 0;
	list->data.width = 0;
	list->data.prscn = 0;
	list->data.var = '0';
	list->data.var_type = 0;
	list->data.w_crctn = 0;
	list->out.out = NULL;
	list->out.ch_zero = 0;
	list->out.u_out = NULL;
	list->out.below_zero = 0;
	list->next = NULL;
	list->data.error = '0';
	return (list);
}

void		lst_free(t_lst **list)
{
	t_lst *tmp;

	if (list != NULL)
	{
		while (*list != NULL)
		{
			tmp = *list;
			*list = (*list)->next;
			if (tmp->out.out != NULL)
				free(tmp->out.out);
			if (tmp->out.u_out != NULL)
				free(tmp->out.u_out);
			free(tmp);
		}
		free(*list);
		*list = NULL;
	}
}
