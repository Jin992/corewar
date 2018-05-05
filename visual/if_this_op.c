/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_this_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakovet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:22:06 by ymakovet          #+#    #+#             */
/*   Updated: 2018/05/05 13:22:07 by ymakovet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	if_this_op2(t_VM *vm, int cord)
{	
	if (cord == 9)
		mvwprintw(vm->lite, 6, 2, "zjmp");
	if (cord == 10)
		mvwprintw(vm->lite, 6, 2, "ldi");
	if (cord == 11)
		mvwprintw(vm->lite, 6, 2, "sti");
	if (cord == 12)
		mvwprintw(vm->lite, 6, 2, "fork");
	if (cord == 13)
		mvwprintw(vm->lite, 6, 2, "lld");
	if (cord == 14)
		mvwprintw(vm->lite, 6, 2, "lldi");
	if (cord == 15)
		mvwprintw(vm->lite, 6, 2, "lfork");
	if (cord == 16)
		mvwprintw(vm->lite, 6, 2, "aff");
}

void	if_this_op(t_VM *vm, int cord)
{
	if (cord > 0 && cord < 9)
	{
		if (cord == 1)
			mvwprintw(vm->lite, 6, 2, "live");
		if (cord == 2)
			mvwprintw(vm->lite, 6, 2, "ld");
		if (cord == 3)
			mvwprintw(vm->lite, 6, 2, "st");
		if (cord == 4)
			mvwprintw(vm->lite, 6, 2, "add");
		if (cord == 5)
			mvwprintw(vm->lite, 6, 2, "sub");
		if (cord == 6)
			mvwprintw(vm->lite, 6, 2, "and");
		if (cord == 7)
			mvwprintw(vm->lite, 6, 2, "or");
		if (cord == 8)
			mvwprintw(vm->lite, 6, 2, "xor");
	}
	else if (cord > 0 && cord < 17)
		if_this_op2(vm, cord);
	wrefresh(vm->lite);
}
