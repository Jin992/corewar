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
	local.players_qnt = argc - 1;
	local.processes = NULL;
	ft_memset(local.memory, 0, MEM_SIZE);
	ft_memset(local.memory_color, 0, MEM_SIZE);
	get_players(argv, &local);
	load_players_to_memory(&local);
	processor(&local);
	ld_operation(&local, local.processes);
	//print_memory(local.memory);

	return 0;
}