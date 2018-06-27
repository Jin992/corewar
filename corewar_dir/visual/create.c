/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakovet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:43:23 by ymakovet          #+#    #+#             */
/*   Updated: 2018/04/28 11:43:24 by ymakovet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		it_is_proces(t_vm *vm, int i)
{
	t_process *tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (tmp->pc == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_proces(t_vm *vm, int *i, int x, int y)
{
	int color;

	color = 10 * vm->memory_color[*i];
	if (color == 0)
		color = 100;
	wattron(vm->main_field, COLOR_PAIR(color));
	mvwprintw(vm->main_field, y, x, "%.2x", vm->memory[*i]);
	wattroff(vm->main_field, COLOR_PAIR(color));
	mvwprintw(vm->main_field, y, x + 2, " ");
	(*i)++;
}

void	print_else(t_vm *vm, int *i, int x, int y)
{
	wattron(vm->main_field, COLOR_PAIR(vm->memory_color[*i]));
	mvwprintw(vm->main_field, y, x, "%.2x", vm->memory[*i]);
	wattroff(vm->main_field, COLOR_PAIR(vm->memory_color[*i]));
	mvwprintw(vm->main_field, y, x + 2, " ");
	(*i)++;
}

void	ft_create_map(t_vm *vm)
{
	int			y;
	int			x;
	int			i;
	t_process	*tmp;

	y = -1;
	i = 0;
	tmp = vm->processes;
	while (++y < 192)
	{
		x = 0;
		while (x < 192)
		{
			if (i < MEM_SIZE)
			{
				if (it_is_proces(vm, i) == 1)
					print_proces(vm, &i, x, y);
				else
					print_else(vm, &i, x, y);
			}
			x += 3;
		}
	}
}
