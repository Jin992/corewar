//
// Created by Evgen ARTESHCHUK on 4/23/18.
//
#include "vm.h"

static void	init_player(char *player, t_players *player_st)
{
	int				fd_in;
	unsigned char	buff;
	int  			cnt;
	unsigned char	exec_size[4];

	cnt = 0;
	fd_in = open(player, O_RDONLY);
	ft_bzero(player_st->player_exec, MEM_SIZE / 6);
	while (read(fd_in, &buff, 1) > 0)
	{
		if (cnt < 4)
			player_st->magic[cnt] = (int)buff;
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
	close(fd_in);
}

void	get_players(char **argv, t_VM *machine)
{
	int cnt;

	cnt = 0;
	while (++cnt <= machine->players_qnt)
		init_player(argv[cnt], &machine->player[cnt - 1]);
}