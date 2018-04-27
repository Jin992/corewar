#include <stdio.h>
#include "includes/vm.h"


int main(int argc, char **argv)
{
	t_VM	local;

	if (argc < 2 || argc > 5)
	{
		usage();
		return (0);
	}
	init_ncurses(&local);
	local.players_qnt = argc - 1;
	local.processes = NULL;
	local.proceses_live = 0;
	local.cycle_to_die = CYCLE_TO_DIE;
	local.period = CYCLE_TO_DIE;
	local.max_check = 0;
	ft_memset(local.memory, 0, MEM_SIZE);
	ft_memset(local.memory_color, 0, MEM_SIZE);
	get_players(argv, &local);//Валідація
	load_players_to_memory(&local);//Валідація
	processor(&local);//покищо без валідацї
	// print_memory(&local, 0);
	return 0;
}