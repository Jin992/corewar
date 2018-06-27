/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:44:02 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/22 13:44:03 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_join_new_l(char *line, char **rez)
{
	char		*ptr1;
	char		*tmp;

	tmp = ft_strjoin(*rez, line);
	ptr1 = ft_strjoin(tmp, "\n");
	free(*rez);
	free(tmp);
	*rez = ptr1;
}

t_data			*ft_multi_lines(t_data *data, char **rez)
{
	char		**split;
	char		*ptr1;
	char		*ptr2;
	char		*tmp;

	while (data)
	{
		data->is_readed = 1;
		if (!(ptr1 = ft_strchr(data->line, '"')))
			ft_join_new_l(data->line, rez);
		else
		{
			split = ft_strsplit(data->line, '"');
			ptr2 = ft_strdup(split[0]);
			tmp = ft_strjoin(*rez, ptr2);
			free(ptr2);
			ptr2 = *rez;
			*rez = tmp;
			free(ptr2);
			ft_clean_map(split);
			break ;
		}
		data = data->next;
	}
	return (data);
}

char			*lines_n_c(t_data *data, char *ptr1, char *ptr2)
{
	char		**split;
	char		*rez;

	ptr1 = ft_strchr(data->line, '"');
	ptr2 = ft_strrchr(data->line, '"');
	if (ptr2 == ptr1 + 1)
		return (ft_strnew(1));
	if (ptr1 == ptr2)
	{
		split = ft_strsplit(data->line, '"');
		if (split[1] != NULL)
			rez = ft_strjoin(split[1], "\n");
		else
			rez = ft_strdup("\n");
		ft_clean_map(split);
		data = data->next;
		data = ft_multi_lines(data, &rez);
	}
	else
	{
		split = ft_strsplit(data->line, '"');
		rez = ft_strdup(split[1]);
		ft_clean_map(split);
	}
	return (rez);
}

void			read_name(t_data *data, t_header *asmus)
{
	char		*rez;
	int			i;

	while (data)
	{
		i = 0;
		data->is_readed = 1;
		while (data->line[i] == '\t' || data->line[i] == ' ')
			i++;
		if (ft_strncmp(data->line + i, ".name", 5) == 0)
			break ;
		data = data->next;
	}
	if (data == NULL)
		ft_error_exit(11, 0, 0, NULL);
	rez = lines_n_c(data, NULL, NULL);
	if (ft_strlen(rez) > PROG_NAME_LENGTH)
	{
		free(rez);
		ft_error_exit(7, 0, 0, NULL);
	}
	ft_strcpy(asmus->prog_name, rez);
	free(rez);
}

void			read_comment(t_data *data, t_header *asmus)
{
	char		*rez;
	int			i;

	while (data)
	{
		i = 0;
		data->is_readed = 1;
		while (data->line[i] == '\t' || data->line[i] == ' ')
			i++;
		if (ft_strncmp(data->line + i, ".comment", 8) == 0)
			break ;
		data = data->next;
	}
	if (data == NULL)
		ft_error_exit(10, 0, 0, NULL);
	rez = lines_n_c(data, NULL, NULL);
	if (ft_strlen(rez) > COMMENT_LENGTH)
	{
		free(rez);
		ft_error_exit(8, 0, 0, NULL);
	}
	ft_strcpy(asmus->comment, rez);
	free(rez);
}
