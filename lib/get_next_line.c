/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:21:44 by earteshc          #+#    #+#             */
/*   Updated: 2018/03/22 16:49:57 by jdoeeshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			get_next_line(int fd, char **line)
{
	static char	*arr[100];
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || !line || BUFF_SIZE < 1 ||
			(res = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	arr[fd] = arr[fd] ? arr[fd] : ft_strdup("");
	tmp = arr[fd];
	buff[res] = '\0';
	arr[fd] = ft_strjoin(arr[fd], buff);
	free(tmp);
	tmp = arr[fd];
	if (!ft_strlen(arr[fd]))
		return (0);
	else if (ft_strchr(arr[fd], '\n') &&
	(*line = ft_strsub(arr[fd], 0, ft_strchr(arr[fd], '\n') - arr[fd])))
		arr[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
	else if (!res && ft_strlen(arr[fd]) && (*line = ft_strdup(arr[fd])))
		arr[fd] = NULL;
	else
		return (get_next_line(fd, line));
	free(tmp);
	return (1);
}
