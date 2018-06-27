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

void	if_this_op2(t_vm *vm, int cord)
{
	if (cord == 9)
		mvwprintw(vm->help_menu_2, 2, 2,
		"zjmp - indirect transition.\n  Takes T_DIR");
	if (cord == 10)
		mvwprintw(vm->help_menu_2, 2, 2,
		"ldi - indirect loading by index.\n  Takes T_REG | T_IND | T_DIR");
	if (cord == 11)
		mvwprintw(vm->help_menu_2, 2, 2,
			"sti - indirect record by index.\n  Takes T_REG | T_IND | T_DIR");
	if (cord == 12)
		mvwprintw(vm->help_menu_2, 2, 2,
			"fork - new process.\n  Takes T_DIR");
	if (cord == 13)
		mvwprintw(vm->help_menu_2, 2, 2, "lld - LONG ld");
	if (cord == 14)
		mvwprintw(vm->help_menu_2, 2, 2, "lldi - LONG ldi");
	if (cord == 15)
		mvwprintw(vm->help_menu_2, 2, 2, "lfork - LONG fork");
	if (cord == 16)
		mvwprintw(vm->help_menu_2, 2, 2,
			"aff - displaying the value on the screen.\nTakes T_REG");
	if (cord == 8)
		mvwprintw(vm->help_menu_2, 2, 2,
			"xor - bitwise XOR operation.\n   Takes T_REG | T_IND | T_DIR");
}

void	if_this_op(t_vm *vm, int cord)
{
	wattron(vm->help_menu_2, A_BOLD);
	if (cord == 1)
		mvwprintw(vm->help_menu_2, 2, 2, "live - 'life' of process.");
	else if (cord == 2)
		mvwprintw(vm->help_menu_2, 2, 2,
			"ld - indirect loading.\n    Takes T_DIR | T_IND");
	else if (cord == 3)
		mvwprintw(vm->help_menu_2, 2, 2,
			" st - indirect record.\n   Takes T_REG");
	else if (cord == 4)
		mvwprintw(vm->help_menu_2, 2, 2,
			"add - addition.\n   Takes T_REG");
	else if (cord == 5)
		mvwprintw(vm->help_menu_2, 2, 2,
			"sub - subtraction.\n   Takes T_REG");
	else if (cord == 6)
		mvwprintw(vm->help_menu_2, 2, 2,
			"and - bitwise AND operation.\n   Takes T_REG | T_IND | T_DIR");
	else if (cord == 7)
		mvwprintw(vm->help_menu_2, 2, 2,
			"or - bitwise OR operation.\n   Takes T_REG | T_IND | T_DIR");
	else
		if_this_op2(vm, cord);
	wrefresh(vm->help_menu_2);
	wattroff(vm->help_menu_2, A_BOLD);
}
