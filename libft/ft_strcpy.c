/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:58:39 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/15 13:11:20 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *dst_start;

	dst_start = dst;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst_start);
}
