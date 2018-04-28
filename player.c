//
// Created by Evgen ARTESHCHUK on 4/23/18.
//
#include "includes/vm.h"

static void	validate_file(t_players *player_st, int cnt)
{
	if (((COMMENT_LENGTH + PROG_NAME_LENGTH + player_st->exec_size + 4) + 12) != cnt)
	{
		printf("SOMETHING WRONG\n");
		exit (1);
	}
	if (player_st->exec_size < 0)
	{
		printf("BAD PLAYER\n");
		exit (1);
	}
	if (REVERSE_4_BYTES(*(int32_t*)&player_st->magic[0]) != COREWAR_EXEC_MAGIC)
	{
		printf("COREWAR_EXEC_MAGIC ERROR\n");
		exit (1);
	}
}

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
	validate_file(player_st,cnt);
	close(fd_in);
}

void	get_players(char **argv, t_VM *machine)
{
	int cnt;
	int i;

	i = 1;
	cnt = 0;
	while (argv[i])
	{
		if (find_core_file(argv[i]))
		{
			++cnt;
			machine->players_qnt++;
			machine->player[cnt - 1].last_live = 0;
			machine->player[cnt - 1].live_cur_period = 0;
			machine->player[cnt - 1].player_nbr = ((cnt - 1 )+ 1) * -1;
			init_player(argv[cnt], &machine->player[cnt - 1]);
		}
		i++;
	}
}