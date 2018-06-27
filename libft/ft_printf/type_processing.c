/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:12:08 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 18:21:42 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		fill_sample(int (**f)(t_lst *, va_list *))
{
	f[0] = &char_string;
	f[1] = &unicode_string;
	f[2] = &digit_ptr;
	f[3] = &digit_dec;
	f[4] = &digit_dec;
	f[5] = &digit_dec;
	f[6] = &digit_oct;
	f[7] = &digit_oct;
	f[8] = &digit_unsigned;
	f[9] = &digit_unsigned;
	f[10] = &digit_hex;
	f[11] = &digit_hex;
	f[12] = &char_c;
	f[13] = &char_c_c;
	f[14] = &percent;
	f[15] = &error_input;
	f[16] = &digit_float;
	f[17] = &digit_float;
}

int				type_handler(t_lst *list, va_list *ap)
{
	int		i;
	char	*sample;
	int		(*f[18])(t_lst *, va_list *);

	if (list == NULL)
		return (-1);
	i = 0;
	fill_sample(f);
	sample = "sSpdDioOuUxXcC%wfF";
	while (sample[i] != '\0')
	{
		if (sample[i] == list->data.var)
			break ;
		i++;
		if (sample[i] == '\0')
			return (0);
	}
	if (f[i](list, ap) == -1)
		return (-1);
	return (0);
}
