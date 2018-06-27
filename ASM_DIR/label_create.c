/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:36:29 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/09 11:36:30 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			give_op_num(t_code *tmp)
{
	(ft_strequ(tmp->op_code, "live")) ? (tmp->op_num = 1) : 0;
	(ft_strequ(tmp->op_code, "ld")) ? (tmp->op_num = 2) : 0;
	(ft_strequ(tmp->op_code, "st")) ? (tmp->op_num = 3) : 0;
	(ft_strequ(tmp->op_code, "add")) ? (tmp->op_num = 4) : 0;
	(ft_strequ(tmp->op_code, "sub")) ? (tmp->op_num = 5) : 0;
	(ft_strequ(tmp->op_code, "and")) ? (tmp->op_num = 6) : 0;
	(ft_strequ(tmp->op_code, "or")) ? (tmp->op_num = 7) : 0;
	(ft_strequ(tmp->op_code, "xor")) ? (tmp->op_num = 8) : 0;
	(ft_strequ(tmp->op_code, "lld")) ? (tmp->op_num = 13) : 0;
	(ft_strequ(tmp->op_code, "aff")) ? (tmp->op_num = 16) : 0;
	if (tmp->op_num < 1)
	{
		tmp->label_size = 2;
		(ft_strequ(tmp->op_code, "zjmp")) ? (tmp->op_num = 9) : 0;
		(ft_strequ(tmp->op_code, "ldi")) ? (tmp->op_num = 10) : 0;
		(ft_strequ(tmp->op_code, "sti")) ? (tmp->op_num = 11) : 0;
		(ft_strequ(tmp->op_code, "fork")) ? (tmp->op_num = 12) : 0;
		(ft_strequ(tmp->op_code, "lldi")) ? (tmp->op_num = 14) : 0;
		(ft_strequ(tmp->op_code, "lfork")) ? (tmp->op_num = 15) : 0;
	}
}

void			give_label_position(t_code *code, int pos)
{
	char		*ptr;

	while (code)
	{
		if (code->label != NULL)
			code->label_position = pos;
		if (code->op_code[0] != '\0')
			code->opcode_position = pos;
		pos++;
		if (code->op_num != 1 && code->op_num != 9 &&
			code->op_num != 12 && code->op_num != 0 && code->op_num != 15)
			pos++;
		ptr = code->way;
		while (*ptr != '\0')
		{
			if (*ptr == 'r')
				pos++;
			else if (*ptr == 'd')
				pos += code->label_size;
			else
				pos += 2;
			ptr++;
		}
		code = code->next;
	}
}

t_labels		*new_labels_l(char *label1)
{
	t_labels	*node;

	node = (t_labels*)malloc(sizeof(t_labels));
	node->label = ft_strdup(label1);
	node->opcode_position = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_labels		*ft_label_cr(t_labels **labels_t, char *label, t_labels *l_list)
{
	t_labels	*l_list_prev;

	if (*labels_t == NULL)
	{
		*labels_t = new_labels_l(label);
		l_list = *labels_t;
	}
	else
	{
		l_list->next = new_labels_l(label);
		l_list_prev = l_list;
		l_list = l_list->next;
		l_list->prev = l_list_prev;
	}
	return (l_list);
}
