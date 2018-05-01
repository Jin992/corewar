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

void			proccessor_kill_this_2(t_process **kill_me)
{
	t_process *die;

	if (!((*kill_me)->prev) && (*kill_me)->next)
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = NULL;
		free(die);
	}
	else
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = die->prev;
		free(die);
	}
}

void			proccessor_kill_this(t_process **kill_me)
{
	t_process *die;

	if (!(kill_me))
		return ;
	if (!((*kill_me)->prev) && !((*kill_me)->next))
	{
		free(*kill_me);
		*kill_me = NULL;
	}
	else if (!((*kill_me)->prev) && (*kill_me)->next)
	{
		die = *kill_me;
		*kill_me = (*kill_me)->next;
		(*kill_me)->prev = NULL;
		free(die);
	}
	else
		proccessor_kill_this_2(kill_me);
}
