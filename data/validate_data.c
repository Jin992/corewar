/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:56:16 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/28 16:56:17 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			find_core_file(char *str)
{
	int i;
	int fd;

	i = ft_strlen(str);
	if (str[i - 1] == 'r' && str[i - 2] == 'o' 
		&& str[i - 3] == 'c'&& str[i - 4] == '.' && i >= 4)
	{
		if ((fd = open(str, O_RDONLY)) <= 0)
		{
			close(fd);
			return (0);
		}
		return (fd);
	}
	return (0);
}

int 		is_int(char *str)
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

int			parse_dump(t_VM * vm, char **argv, int i)
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

int			parse_e_flag(t_VM * vm, char **argv, int i)
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

int 		find_empty_slot(t_VM * vm)
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

int 		find_empty_slot_in_number(t_VM * vm, int slot)
{
	int i;

	i = 0;
	if (vm->empty[slot - 1] != 0)
		return (find_empty_slot(vm));
	return (slot);
}

void			parse_player(t_VM * vm, char **argv, int *i)
{
	int fd;

	if (ft_strequ(argv[*i], "-n"))
	{
		if (argv[*i + 1] && (argv[*i + 2] && (fd = find_core_file(argv[*i + 2])) > 0))
		{
			if (ft_atoi(argv[*i + 1]) > 0 && ft_atoi(argv[*i + 1]) <= 4)
				get_players(argv[*i + 2], vm, find_empty_slot_in_number(vm, ft_atoi(argv[*i + 1])), fd);
			else
				get_players(argv[*i + 2], vm, find_empty_slot(vm), fd);
			*i += 2;
		}
		else
			usage();
	}
	else
		if ((fd = find_core_file(argv[*i])) > 0)
			get_players(argv[*i], vm, find_empty_slot(vm), fd);
}

int			parse_flags(int argc, char **argv, t_VM *local)
{
	int i;

	i = 1;
	while(argv[i])
	{
		if (ft_strequ(argv[i], "-v"))
			local->visual = 1;
		else if (ft_strequ(argv[i], "-s"))
			local->visual = 2;
		else if (ft_strequ(argv[i], "-a"))
			local->aff = 1;
		else if (ft_strequ(argv[i], "-e"))
		{
			if (!(parse_e_flag(local, argv, i + 1)))
				return (0);
		}
		else if (ft_strequ(argv[i], "-d") || ft_strequ(argv[i], "-dump"))
		{
			if (!(parse_dump(local, argv, i + 1)))
				return (0);
		}
		else
			parse_player(local, argv, &i);
		i++;
	}
	return (1);
}