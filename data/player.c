/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:33:18 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/04/30 16:33:22 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	validate_file(t_players *player_st, int cnt, char *file)
{
	if ((COMMENT_LENGTH + PROG_NAME_LENGTH
		+ player_st->exec_size + 4 + 12) != cnt)
	{
		ft_printf("Error: File %s : has a code size"
			"that differ from what its header says\n", file);
		exit(1);
	}
	if (REVERSE_4_BYTES(*(int32_t*)&player_st->magic[0]) != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error: File %s : COREWAR_EXEC_MAGIC ERROR\n", file);
		exit(1);
	}
	if (player_st->exec_size > 682)
	{
		ft_printf("Error: File %s : has too large (%d bytes > 682 bytes)\n", file, player_st->exec_size);
		exit(1);
	}
}

static void	init_player(int fd_in, t_players *player_st, char *file)
{
	int				cnt;
	unsigned char	buff;
	unsigned char	exec_size[4];

	cnt = 0;
	ft_bzero(player_st->player_exec, MEM_SIZE / 6);
	while (read(fd_in, &buff, 1) > 0)
	{
		if (cnt < 4)
			player_st->magic[cnt] = buff;
		else if (cnt < PROG_NAME_LENGTH + 4)
			player_st->name[cnt - 4] = (int)buff;
		else if (cnt < 140 && cnt > 135)
			exec_size[cnt - 136] = buff;
		else if (cnt > 139 && cnt < 140 + COMMENT_LENGTH)
			player_st->comment[cnt - 139] = buff;
		else if (cnt > 143 + COMMENT_LENGTH)
			player_st->player_exec[cnt - (144 + COMMENT_LENGTH)] = buff;
		cnt++;
	}
	player_st->exec_size = REVERSE_4_BYTES(*(int32_t *)exec_size);
//	validate_file(player_st, cnt, file);
}

void		get_players(char *str, t_VM *vm, int cnt, int fd)
{
	vm->players_qnt++;
	vm->player[cnt - 1].last_live = 0;
	vm->player[cnt - 1].live_cur_period = 0;
	vm->player[cnt - 1].player_nbr = ((cnt - 1) + 1) * -1;
	vm->empty[cnt - 1] = 1;
	init_player(fd, &vm->player[cnt - 1], str);
}
