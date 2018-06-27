/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:50:19 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/02 17:50:20 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data			*ft_big_name(t_data *data)
{
	char		*ptr1;
	int			l_c[2];

	data = data->next;
	l_c[0] = 0;
	l_c[1] = 0;
	while (data)
	{
		data->type_line = NAME_COOMENT;
		ptr1 = data->line;
		while (*ptr1 == '\t' || *ptr1 == ' ')
			ptr1++;
		if (ft_strncmp(ptr1, ".comment", 8) == 0)
			ft_error_exit(2, data->num_line, ptr1 - data->line + 8, NULL);
		if (ft_strrchr(ptr1, '"'))
		{
			data->type_line = END_QUOTE;
			break ;
		}
		l_c[0] = data->num_line;
		l_c[1] = ft_strlen(data->line);
		data = data->next;
	}
	(data == NULL) ? ft_error_exit(2, l_c[0], l_c[1], NULL) : 0;
	return (data);
}

void			ft_parsing_name(t_data *data, t_valid *valid, char *line)
{
	char		*ptr1;
	char		*ptr2;

	while (data)
	{
		line = data->line;
		while (*line == '\t' || *line == ' ')
			line++;
		if (line && ft_strncmp(line, ".name", 5) == 0)
		{
			data->type_line = START_QUOTE;
			valid->find_name++;
			if (valid->find_name > 1)
				ft_error_exit(2, data->num_line, 0, NULL);
			ptr1 = ft_strchr(line, '"');
			ptr2 = ft_strrchr(line, '"');
			if (ptr1 == NULL)
				ft_error_exit(2, data->num_line, line - data->line + 5, NULL);
			if (ptr1 == ptr2)
				data = ft_big_name(data);
			else
				data->type_line = DOUBLE_QUOTE;
		}
		data = data->next;
	}
}

t_data			*ft_big_comment(t_data *data)
{
	char		*ptr1;
	int			l_c[2];

	data = data->next;
	l_c[0] = 0;
	l_c[1] = 0;
	while (data)
	{
		data->type_line = NAME_COOMENT;
		ptr1 = data->line;
		while (*ptr1 == '\t' || *ptr1 == ' ')
			ptr1++;
		if (ft_strncmp(ptr1, ".name", 5) == 0)
			ft_error_exit(3, data->num_line, ptr1 - data->line + 5, NULL);
		if (ft_strrchr(ptr1, '"'))
		{
			data->type_line = END_QUOTE;
			break ;
		}
		l_c[0] = data->num_line;
		l_c[1] = ft_strlen(data->line);
		data = data->next;
	}
	(data == NULL) ? ft_error_exit(3, l_c[0], l_c[1], NULL) : 0;
	return (data);
}

void			ft_parsing_comment(t_data *data, t_valid *valid, char *line)
{
	char		*ptr1;
	char		*ptr2;

	while (data)
	{
		line = data->line;
		while (*line == '\t' || *line == ' ')
			line++;
		if (line && ft_strncmp(line, ".comment", 8) == 0)
		{
			data->type_line = START_QUOTE;
			valid->find_comment++;
			if (valid->find_comment > 1)
				ft_error_exit(3, data->num_line, 0, NULL);
			ptr1 = ft_strchr(line, '"');
			ptr2 = ft_strrchr(line, '"');
			if (ptr1 == NULL)
				ft_error_exit(3, data->num_line, line - data->line + 8, NULL);
			if (ptr1 == ptr2)
				data = ft_big_comment(data);
			else
				data->type_line = DOUBLE_QUOTE;
		}
		data = data->next;
	}
}

void			parsing_data(t_data *data, t_valid *valid)
{
	ft_parsing_name(data, valid, NULL);
	ft_parsing_comment(data, valid, NULL);
	ft_parsing_invalid_symbols(data, valid);
}
