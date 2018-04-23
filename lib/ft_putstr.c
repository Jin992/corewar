/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:58:03 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/12 17:33:25 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_putstr(char const *s)
{
	size_t	i;
	ssize_t	w_symb;

	i = 0;
	w_symb = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		w_symb += write(1, &s[i], 1);
		i++;
	}
	return (w_symb);
}
