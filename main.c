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
	local.proceses_live = 0;
	ft_memset(local.memory, 0, MEM_SIZE);
	ft_memset(local.memory_color, 0, MEM_SIZE);
	get_players(argv, &local);//Валідація
	load_players_to_memory(&local);//Валідація
	// if (local.processes)
		processor(&local);//покищо без валідацї
	// while(local.processes)
	// {
	// 	printf("pos = %d\n", local.processes->pc);
	//  local.processes = local.processes->next;
	// }
	print_memory(&local, 0);
	return 0;
}