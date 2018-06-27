/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:55:37 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/28 11:55:37 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_error_exit_2(int type, int num_line, int num_char)
{
	if (type == 6)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n",
			num_line, num_char);
	else if (type == 7)
		ft_printf("Champion name too long (Max length %d)\n", PROG_NAME_LENGTH);
	else if (type == 8)
		ft_printf("Champion comment too long (Max length %d)\n",
			COMMENT_LENGTH);
	else if (type == 9)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] END \"(null)\"\n",
			num_line, num_char);
	else if (type == 10)
		ft_printf("Syntax error - no \".comment\"\n");
	else if (type == 11)
		ft_printf("Syntax error - no \".name\"\n");
	else
		ft_printf("Error %d\n", type);
	exit(0);
}

void			ft_error_exit(int type, int num_line, int num_char, char *str)
{
	num_char++;
	if (type == 1)
		ft_printf("Lexical error at [%d:%d]\n", num_line, num_char);
	else if (type == 2)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \".name\"\n",
			num_line, num_char, "COMMAND_NAME");
	else if (type == 3)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \".comment\"\n",
			num_line, num_char, "COMMAND_COMMENT");
	else if (type == 4)
		ft_printf("Invalid parameter for instruction %s\n", str);
	else if (type == 5)
		ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] %s \"%s\"\n",
			num_line, num_char, "INSTRUCTION", str);
	else
		ft_error_exit_2(type, num_line, num_char);
	(str != NULL) ? free(str) : 0;
	exit(0);
}

void			ft_clean_map(char **map)
{
	int			u;

	u = 0;
	while (map[u] != NULL)
	{
		free(map[u]);
		u++;
	}
	free(map);
}

void			ft_struct_free(t_code *code)
{
	t_code *one;

	while (code)
	{
		one = code;
		code = code->next;
		(one->label != NULL) ? free(one->label) : 0;
		(one->dir_1 != NULL) ? free(one->dir_1) : 0;
		(one->dir_2 != NULL) ? free(one->dir_2) : 0;
		(one->dir_3 != NULL) ? free(one->dir_3) : 0;
		(one->ind_1 != NULL) ? free(one->ind_1) : 0;
		(one->ind_2 != NULL) ? free(one->ind_2) : 0;
		(one->ind_3 != NULL) ? free(one->ind_3) : 0;
		free(one);
	}
}

void			ft_data_labels_free(t_data *data, t_labels *labels_list)
{
	t_data		*one;
	t_labels	*leb;

	while (data)
	{
		one = data;
		data = data->next;
		(one->line != NULL) ? free(one->line) : 0;
		free(one);
	}
	while (labels_list)
	{
		leb = labels_list;
		labels_list = labels_list->next;
		(leb->label != NULL) ? free(leb->label) : 0;
		free(leb);
	}
}
