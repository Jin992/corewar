/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:12:51 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/01 18:12:53 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_register(t_process *cur, t_VM *vm, int nbr)
{
	int i;
	int j;
	int k;

	i = 0;
	wattron(vm->help_menu, COLOR_PAIR((cur->color + 1)));
	mvwprintw(vm->help_menu,  2, 0, "\t Process index %d", nbr);
	mvwprintw(vm->help_menu, 3 + i, 16, "Process carry status: %3d", cur->carry);
	mvwprintw(vm->help_menu, 4 + i, 16, "Process curent PC: %6d", cur->pc);
	while (i < REG_NUMBER)
	{
		j = 0;
		k = 0;
		mvwprintw(vm->help_menu, 3 + i, 0 + j, "%.2x: ", i);
		while (j < (REG_SIZE * 3))
		{
			mvwprintw(vm->help_menu, 3 + i, 0 + j + 4, "%.2x ", cur->reg[i][k]);
			k++;
			j += 3;
		}
		i++;
	}
	wattroff(vm->help_menu, COLOR_PAIR((cur->color + 1)));

}

void	get_mouse(t_VM *vm)
{
	int i;
	MEVENT mouse;
	
	i = 0;
	if ((getmouse(&mouse)) == OK)
	{
		t_process *tmp;
		tmp = vm->processes;
		while (tmp)
		{
			if (tmp->pc == ((mouse.y - 3) * 64) + (mouse.x / 3))
			{
				print_register(tmp, vm, i);
				break ;
			}
			i++;
			tmp = tmp->next;
		}
	}
	wrefresh(vm->help_menu);
}