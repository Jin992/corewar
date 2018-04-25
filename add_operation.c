/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:32:38 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/24 18:47:42 by jdoeorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

void		add_operation(t_VM *machine, t_process *cur)
{
	int shift = 0;
	ft_printf("add_operation\n");
	cur->pc += shift;
}
