/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:17:55 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/22 14:17:56 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_go_to_zero(t_code *tmp)
{
	ft_bzero((void*)tmp->way, 4);
	ft_bzero((void*)tmp->op_code, 6);
	tmp->label = NULL;
	tmp->dir_1 = NULL;
	tmp->dir_2 = NULL;
	tmp->dir_3 = NULL;
	tmp->ind_1 = NULL;
	tmp->ind_2 = NULL;
	tmp->ind_3 = NULL;
	tmp->reg[0] = 0;
	tmp->reg[1] = 0;
	tmp->reg[2] = 0;
	tmp->op_num = 0;
	tmp->label_size = 4;
	tmp->label_position = 0;
	tmp->opcode_position = -1;
	tmp->codage = -1;
	tmp->next = NULL;
	tmp->prev = NULL;
}

void			new_code_cons(t_code *tmp, char **label, char *line, int u)
{
	if (tmp->label == NULL && *label != NULL)
		tmp->label = ft_strdup(*label);
	if (*label != NULL)
	{
		free(*label);
		*label = NULL;
	}
	ft_strncpy(tmp->op_code, line, u);
	give_op_num(tmp);
}

t_code			*new_code(char *line, char **label, int u)
{
	t_code		*tmp;

	tmp = (t_code*)malloc(sizeof(t_code));
	while (*line == ' ' || *line == '\t')
		line++;
	ft_go_to_zero(tmp);
	while (line[++u] != '\0')
	{
		if (line[u] == ':')
		{
			tmp->label = ft_strnew(u + 1);
			ft_strncpy(tmp->label, line, u++);
			while (line[u] == ' ' || line[u] == '\t')
				u++;
			line = line + u;
			u = 0;
		}
		else if (line[u] == ' ' || line[u] == '\t' || line[u] == '%')
		{
			new_code_cons(tmp, label, line, u);
			break ;
		}
	}
	build_arguments(line + u, tmp, -1);
	return (tmp);
}

t_code			*ft_code_cr(t_data *data, t_code **c, t_code *lst, char **label)
{
	t_code		*l_prev;

	if (*c == NULL)
	{
		*c = new_code(data->line, label, -1);
		lst = *c;
	}
	else
	{
		lst->next = new_code(data->line, label, -1);
		l_prev = lst;
		lst = lst->next;
		lst->prev = l_prev;
	}
	return (lst);
}

t_code			*exec_code(t_data *data, t_code *code, t_labels **l_l, int i)
{
	t_code		*lst;
	t_labels	*l_list;
	char		*label;
	int			rez;

	label = NULL;
	while (data && (i += 1) && data->is_readed != 0)
		data = data->next;
	while (data)
	{
		rez = ft_isnoempty(data->line, &label);
		if ((rez == 2 || rez == 1) && label != NULL)
			l_list = ft_label_cr(l_l, label, l_list);
		(rez == 1) ? lst = ft_code_cr(data, &code, lst, &label) : 0;
		data = data->next;
		i++;
	}
	(label != NULL) ? free(label) : 0;
	(code == NULL && *l_l == NULL) ? ft_error_exit(9, i, 0, NULL) : 0;
	give_label_position(code, 1);
	return (code);
}
