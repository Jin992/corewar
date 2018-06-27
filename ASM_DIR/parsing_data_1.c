/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:11:22 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/05 13:11:23 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_isnoempty_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!*line || *line == '#' || *line == ';')
		return (0);
	return (1);
}

void			parsing_s_line_n_c(t_data *data, int i, char *ptr)
{
	if (data->type_line == START_QUOTE || data->type_line == DOUBLE_QUOTE)
	{
		if (ft_strncmp(data->line + i, ".comment", 8) == 0)
			i += 8;
		else if (ft_strncmp(data->line + i, ".name", 5) == 0)
			i += 5;
		else
			ft_error_exit(1, data->num_line, i, NULL);
		while (data->line[i] == ' ' || data->line[i] == '\t')
			i++;
		if (data->line[i] != '"')
			ft_error_exit(1, data->num_line, i, NULL);
	}
	if (data->type_line == END_QUOTE || data->type_line == DOUBLE_QUOTE)
	{
		ptr = ft_strrchr(data->line, '"');
		ptr++;
		i = ptr - data->line;
		ptr = data->line;
		while (ptr[i] == '\t' || ptr[i] == ' ')
			i++;
		if (ptr[i] == '\0' || ptr[i] == '#' || ptr[i] == ';')
			return ;
		ft_error_exit(1, data->num_line, i, NULL);
	}
}

void			ft_parsing_invalid_symbols(t_data *data, t_valid *valid)
{
	int			i;

	i = 0;
	while (data)
	{
		if (ft_isnoempty_line(data->line))
		{
			if (data->type_line != EMPTY && data->type_line != OP_CODE)
			{
				i = 0;
				while (data->line[i] == ' ' || data->line[i] == '\t')
					i++;
				parsing_s_line_n_c(data, i, NULL);
			}
			else
				ft_parsing_instructions(data, valid);
		}
		data = data->next;
	}
}
