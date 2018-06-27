/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:02:41 by mminenko          #+#    #+#             */
/*   Updated: 2018/05/03 17:02:43 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			give_op_to_last_label(t_labels *labels, int bytes_num)
{
	while (labels && labels->opcode_position == 0)
	{
		labels->opcode_position = bytes_num + 1;
		labels = labels->prev;
	}
}

void			give_op_to_empty_labels(t_labels *labels, int bytes_num)
{
	t_labels	*labels_l;

	while (labels)
	{
		if (labels->opcode_position > 0)
		{
			labels_l = labels->prev;
			while (labels_l && labels_l->opcode_position == 0)
			{
				labels_l->opcode_position = labels_l->next->opcode_position;
				labels_l = labels_l->prev;
			}
		}
		if (labels->next == NULL)
			break ;
		labels = labels->next;
	}
	if (labels && labels->opcode_position == 0)
		give_op_to_last_label(labels, bytes_num);
}

void			give_op_labels(t_labels *labels_l, t_code *code, int bytes_num)
{
	t_labels	*labels;

	labels = labels_l;
	while (labels_l)
	{
		while (code && code->label == NULL)
			code = code->next;
		if (code && ft_strequ(code->label, labels_l->label))
		{
			labels_l->opcode_position = code->opcode_position;
			code = code->next;
			if (!code)
				break ;
		}
		labels_l = labels_l->next;
	}
	give_op_to_empty_labels(labels, bytes_num);
}
