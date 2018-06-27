/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:09:11 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 13:09:16 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int			is_int(char *str)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (!(ft_isdigit(str[j])))
			return (usage());
		j++;
	}
	if ((long)ft_atoi(str) >= INT_MAX || ft_atoi(str) < 0)
		return (usage());
	return (1);
}

int			parse_dump(t_vm *vm, char **argv, int i)
{
	if (argv[i])
	{
		if (!(is_int(argv[i])))
			return (0);
		vm->dump = ft_atoi(argv[i]);
		return (1);
	}
	return (usage());
}

int			parse_e_flag(t_vm *vm, char **argv, int i)
{
	if (argv[i])
	{
		if (!(is_int(argv[i])))
			return (0);
		vm->e_flag = ft_atoi(argv[i]);
		vm->visual = 3;
		return (1);
	}
	return (usage());
}

int			find_empty_slot(t_vm *vm)
{
	int i;
	int pos;

	pos = -1;
	i = 0;
	while (i < 4)
	{
		if (vm->empty[i] == 0)
			return (i + 1);
		i++;
	}
	usage();
	exit(1);
	return (0);
}

int			find_empty_slot_in_number(t_vm *vm, int slot)
{
	int i;

	i = 0;
	if (vm->empty[slot - 1] != 0)
		return (find_empty_slot(vm));
	return (slot);
}
