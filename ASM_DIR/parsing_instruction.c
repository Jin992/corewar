/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:43:22 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/07 15:43:23 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_search_opcode(char *str, t_valid *valid, int len, int *n_u)
{
	int			rez;
	int			i;
	char		*singl;

	rez = -1;
	i = -1;
	while (*str == ' ' || *str == '\t')
	{
		str++;
		len--;
	}
	while (++i < 16)
		if (ft_strncmp(str, valid->example_instr[i].op_code_v, len) == 0)
		{
			rez = i;
			break ;
		}
	if (rez == -1)
	{
		singl = ft_strnew(len);
		ft_strncpy(singl, str, len);
		ft_error_exit(5, n_u[1], n_u[0], singl);
	}
	return (rez);
}

void			ft_compare(char *cur, char *orig, t_data *data)
{
	char		**map;
	int			u;

	u = 0;
	map = ft_strsplit(orig, ' ');
	if (cur[u] == '\0')
		ft_error_exit(6, data->num_line, 0, NULL);
	while (cur[u] != '\0')
	{
		if (map[u] == NULL || !ft_strchr(map[u], cur[u]))
		{
			ft_clean_map(map);
			ft_error_exit(4, 0, 0, ft_find_instr(data->line));
		}
		u++;
	}
	ft_clean_map(map);
}

int				ft_pars_space_tab(char *line, int i)
{
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

void			pars_label_and_op(t_data *d, t_valid *valid, int i, int start)
{
	char		argm[5];
	int			n_u[2];

	ft_bzero(argm, 5);
	i = ft_pars_space_tab(d->line, i);
	if (d->line[i] == '#' || d->line[i] == ';' || d->line[i] == '\0')
		return ;
	n_u[0] = i;
	n_u[1] = d->num_line;
	while (d->line[i] != '\0')
	{
		if (d->line[i] == ' ' || d->line[i] == '\t' || d->line[i] == '%')
		{
			start = ft_search_opcode(d->line + start, valid, i - start, n_u);
			break ;
		}
		if (!ft_strchr(LABEL_CHARS, d->line[i]))
			ft_error_exit(1, d->num_line, i, NULL);
		i++;
	}
	i = ft_pars_space_tab(d->line, i);
	n_u[0] = i;
	n_u[1] = 0;
	ft_search_arg(d, valid, n_u, argm);
	ft_compare(argm, valid->example_instr[start].argum, d);
}

void			ft_parsing_instructions(t_data *data, t_valid *valid)
{
	int			i;
	int			start;

	i = 0;
	while (data->line[i] == ' ' || data->line[i] == '\t')
		i++;
	start = i;
	while (data->line[i] != '\0')
	{
		if (data->line[i] == ':')
		{
			i++;
			pars_label_and_op(data, valid, i, i);
			return ;
		}
		else if (data->line[i] == ' ' || data->line[i] == '\t' ||
			data->line[i] == '%')
		{
			pars_label_and_op(data, valid, start, start);
			return ;
		}
		else if (!ft_strchr(LABEL_CHARS, data->line[i]))
			ft_error_exit(1, data->num_line, i, NULL);
		i++;
	}
}
