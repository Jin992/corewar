/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_idx_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:02:29 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/05 17:02:30 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

int 		get_idx_mod(short t_ind)
{
	t_ind = t_ind % IDX_MOD;
	if (t_ind < 0)
		return (MEM_SIZE + t_ind);
	return (t_ind);
}