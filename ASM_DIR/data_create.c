/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:35:57 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/09 10:35:57 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_isnoempty(char *line, char **label)
{
	int				i;

	while (*line == ' ' || *line == '\t')
		line++;
	if (!*line || *line == '#' || *line == ';')
		return (0);
	i = 0;
	while (line[i] != '\0' && ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == ':')
	{
		if (*label != NULL)
		{
			free(*label);
			*label = NULL;
		}
		*label = ft_strnew(i);
		ft_strncpy(*label, line, i);
		i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '\0' || line[i] == '#' || line[i] == ';')
			return (2);
	}
	return (1);
}

t_data				*node_new(char *line, int num)
{
	t_data			*rez;

	rez = (t_data *)malloc(sizeof(t_data));
	rez->line = ft_strdup(line);
	rez->num_line = num;
	rez->is_readed = 0;
	rez->type_line = 0;
	rez->next = NULL;
	rez->prev = NULL;
	return (rez);
}

t_data				*create_data(int fd, int i, int u)
{
	char			*line;
	t_data			*rez;
	t_data			*lst;
	t_data			*l_prev;

	rez = NULL;
	while ((u = get_next_line(fd, &line)) > 0)
	{
		if (rez == NULL)
		{
			rez = node_new(line, i);
			lst = rez;
		}
		else
		{
			lst->next = node_new(line, i);
			l_prev = lst;
			lst = lst->next;
			lst->prev = l_prev;
		}
		i++;
		free(line);
	}
	(rez == NULL || u < 0) ? ft_error_exit(9, 1, 0, NULL) : 0;
	return (rez);
}
