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

void		get_key_is(t_vm *vm, char c)
{
	if (c == 100)
		vm->wait = 200;
	else if (c == 122)
		vm->wait = 300;
	else if (c == 120)
		vm->wait = 400;
	else if (c == 99)
		vm->wait = 500;
}

void		get_key(t_vm *vm)
{
	char c;

	while (vm->wait <= 0)
	{
		c = wgetch(vm->main_field);
		if (c == 113)
			vm->wait = 1;
		else if (c == 119)
			vm->wait = 5;
		else if (c == 101)
			vm->wait = 10;
		else if (c == 97)
			vm->wait = 50;
		else if (c == 115)
			vm->wait = 100;
		else
			get_key_is(vm, c);
		get_mouse(vm);
		print_register(vm);
	}
	print_register(vm);
}

void		get_key_2(t_vm *vm)
{
	char c;

	c = wgetch(vm->main_field);
	if (c == 32)
	{
		if (vm->space == 0)
			vm->space = 1;
		else
		{
			vm->space = 0;
			mvwprintw(vm->menu, 1, 2, "** PAUSED **");
		}
	}
	else if (c == 114)
		vm->speed = (vm->speed + SPEED_DELTA > SLOWEST_SPEED)
		? SLOWEST_SPEED : vm->speed + SPEED_DELTA;
	else if (c == 116)
		vm->speed = (vm->speed -
			SPEED_DELTA >= 0) ? vm->speed - SPEED_DELTA : 0;
	if (vm->space == 0)
		get_mouse(vm);
	print_register(vm);
}
