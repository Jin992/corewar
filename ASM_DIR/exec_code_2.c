/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_code_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:33:33 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/09 11:33:34 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_good_line(char *line)
{
	char		*new_l;
	int			i;

	i = 0;
	while (line[i] != '\0' && line[i] != '#' && line[i] != ';')
		i++;
	new_l = ft_strnew(i);
	ft_strncpy(new_l, line, i);
	return (new_l);
}

void			build_arguments_dir(t_code *tmp, char **map, int u, int i)
{
	if (u == 0)
		tmp->dir_1 = ft_strdup(map[u] + i + 1);
	else if (u == 1)
		tmp->dir_2 = ft_strdup(map[u] + i + 1);
	else
		tmp->dir_3 = ft_strdup(map[u] + i + 1);
	tmp->way[u] = 'd';
}

void			build_arguments_indir(t_code *tmp, char **map, int u, int i)
{
	if (u == 0)
		tmp->ind_1 = ft_strdup(map[u] + i);
	else if (u == 1)
		tmp->ind_2 = ft_strdup(map[u] + i);
	else
		tmp->ind_3 = ft_strdup(map[u] + i);
	tmp->way[u] = 'i';
}

void			build_arguments(char *line, t_code *tmp, int u)
{
	int			i;
	char		**map;

	while (*line == ' ' || *line == '\t')
		line++;
	line = ft_good_line(line);
	map = ft_strsplit(line, ',');
	while (map[++u] != NULL)
	{
		i = 0;
		while (map[u][i] == ' ' || map[u][i] == '\t')
			i++;
		if (map[u][i] == 'r' && ft_isdigit(map[u][i + 1]))
		{
			tmp->reg[u] = ft_atoi(map[u] + i + 1);
			tmp->way[u] = 'r';
		}
		else if (map[u][i] == '%')
			build_arguments_dir(tmp, map, u, i);
		else
			build_arguments_indir(tmp, map, u, i);
	}
	free(line);
	ft_clean_map(map);
}
