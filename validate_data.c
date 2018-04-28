/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:56:16 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/28 16:56:17 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h" //free str in validate_name validate_comment validate_exec

int			find_core_file(char *str)
{
	int i;
	int fd;


	i = ft_strlen(str);
	if (str[i - 1] == 'r' && str[i - 2] == 'o' 
		&& str[i - 3] == 'c'&& str[i - 4] == '.' && i >= 4)
	{
		if ((fd = open(str, O_RDONLY)) <= 0)
			return (0);
		close (fd);
		return (1);
	}
	return (0);
}

int			parse_flags(int argc, char **argv, t_VM *local)
{
	int i;

	i = 1;
	while(argv[i])
	{
		if (ft_strequ(argv[i], "-v"))
			local->visual = 1;
		else if (ft_strequ(argv[i], "-l"))
			local->lite = 1;
		i++;
	}
	return (1);

}