/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:07:20 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 13:07:34 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	usage(void)
{
	ft_printf("Usage: ./corewar [-d N -e N -v [-n(x)] <champion1.cor> <...>\n");
	ft_printf("./corewar ./bot_file_1 ... ./bot_file_4");
	ft_printf("-v   	: Graphic mode\n");
	ft_printf("-s   	: Step by step mod\n");
	ft_printf("-d N 	: Dump memory after N cycles then exits");
	ft_printf("-e N  	: Runs N cycles, dumps memory, pauses, then repeats\n");
	exit(1);
	return (0);
}
