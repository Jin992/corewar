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

#include "../includes/data.h"

int			find_core_file(char *str)
{
	int i;
	int fd;

	i = ft_strlen(str);
	if (str[i - 1] == 'r' && str[i - 2] == 'o'
		&& str[i - 3] == 'c' && str[i - 4] == '.' && i >= 4)
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

void		parse_player(t_vm *vm, char **argv, int *i)
{
	int fd;

	if (ft_strequ(argv[*i], "-n"))
	{
		if (argv[*i + 1] && (argv[*i + 2] &&
			(fd = find_core_file(argv[*i + 2])) > 0))
		{
			if (ft_atoi(argv[*i + 1]) > 0 && ft_atoi(argv[*i + 1]) <= 4)
				get_players(argv[*i + 2], vm,
				find_empty_slot_in_number(vm, ft_atoi(argv[*i + 1])), fd);
			else
				get_players(argv[*i + 2], vm, find_empty_slot(vm), fd);
			*i += 2;
		}
		else
			usage();
	}
	else if ((fd = find_core_file(argv[*i])) > 0)
		get_players(argv[*i], vm, find_empty_slot(vm), fd);
	else
		usage();
}

int			parse_flags_2(char **argv, t_vm *local, int *i)
{
	if (ft_strequ(argv[*i], "-v"))
		local->visual = 1;
	else if (ft_strequ(argv[*i], "-s"))
		local->visual = 2;
	else if (ft_strequ(argv[*i], "-a"))
		local->aff = 1;
	else if (ft_strequ(argv[*i], "-e"))
	{
		if (!(parse_e_flag(local, argv, *i + 1)))
			return (0);
		(*i)++;
	}
	else if (ft_strequ(argv[*i], "-d") || ft_strequ(argv[*i], "-dump"))
	{
		if (!(parse_dump(local, argv, *i + 1)))
			return (0);
		(*i)++;
	}
	else
		return (0);
	return (1);
}

int			parse_flags(char **argv, t_vm *local)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if ((parse_flags_2(argv, local, &i)) == 0)
			parse_player(local, argv, &i);
		i++;
	}
	return (1);
}
