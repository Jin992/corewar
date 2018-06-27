/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruction_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 22:33:20 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/07 22:33:21 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_find_instr(char *line)
{
	char		*instr;
	int			i;
	int			start;

	while (*line == ' ' || *line == '\t')
		line++;
	i = 0;
	while (line[i] != '\0' && line[i] != '\t' &&
		line[i] != ' ' && line[i] != ':')
		i++;
	start = 0;
	if (line[i] == ':')
	{
		i++;
		start = i;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		start = i;
		while (line[i] != '\0' && line[i] != '\t' && line[i] != ' ')
			i++;
	}
	instr = ft_strnew(i - start);
	ft_strncpy(instr, line + start, i - start);
	return (instr);
}

int				ft_set_reg(t_data *data, char *str, int u, int i)
{
	int			tmp;
	int			k;

	u++;
	tmp = ft_atoi(str + u);
	if (tmp < 1 || tmp > REG_NUMBER)
		ft_error_exit(1, data->num_line, u + i, NULL);
	while (ft_isdigit(str[u]))
		u++;
	k = u;
	while (str[k] == ' ' || str[k] == '\t')
		k++;
	if (str[k] != '\0' && str[k] != '#' && str[k] != ';' && str[k] != ',')
		ft_error_exit(5, data->num_line, k + i, ft_find_instr(data->line));
	return (u);
}

int				ft_set_direct(t_data *data, char *str, int u, int i)
{
	u++;
	if (str[u] == ':')
	{
		u++;
		while (str[u] != '\0' && ft_strchr(LABEL_CHARS, str[u]))
			u++;
	}
	else
	{
		if (str[u] == '-')
			u++;
		if (!ft_isdigit(str[u]))
			ft_error_exit(1, data->num_line, u + i, NULL);
		while (ft_isdigit(str[u]))
			u++;
	}
	return (u);
}

int				ft_set_indirect(t_data *data, char *str, int u, int i)
{
	if (ft_isdigit(str[u]))
	{
		while (ft_isdigit(str[u]))
			u++;
	}
	else if (str[u] == '-')
	{
		u++;
		if (!ft_isdigit(str[u]))
			ft_error_exit(1, data->num_line, u + i, NULL);
		while (ft_isdigit(str[u]))
			u++;
	}
	else if (str[u] == ':')
	{
		u++;
		while (str[u] != '\0' && ft_strchr(LABEL_CHARS, str[u]))
			u++;
	}
	else
		ft_error_exit(1, data->num_line, u + i, NULL);
	return (u);
}

void			ft_search_arg(t_data *data, t_valid *v, int *n_u, char *argm)
{
	char		*str;
	int			u;

	u = 0;
	str = &data->line[n_u[0]];
	while (str[u] != '\0' && str[u] != '#' && str[u] != ';')
	{
		if (str[u] == 'r' && (argm[n_u[1]++] = 'r') == 'r')
			u = ft_set_reg(data, str, u, n_u[0]);
		else if (str[u] == '%')
		{
			argm[n_u[1]++] = 'd';
			u = ft_set_direct(data, str, u, n_u[0]);
		}
		else if (str[u] != ',' && str[u] != ' ' && str[u] != '\t')
		{
			argm[n_u[1]++] = 'i';
			u = ft_set_indirect(data, str, u, n_u[0]);
		}
		if (str[u] != '\0' && !ft_strchr(v->all_chars, str[u]))
			ft_error_exit(1, data->num_line, u + n_u[0], NULL);
		(n_u[1] > 4) ? ft_error_exit(143, data->num_line, u + n_u[0],
			ft_find_instr(data->line)) : 0;
		(str[u] != '\0') ? u++ : 0;
	}
}
