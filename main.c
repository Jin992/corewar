#include <stdio.h>
#include "vm.h"

void	vm_init(t_VM *machine)
{
	machine
}


int main(int argc, char **argv)
{
	t_VM	local;

	if (argc < 2)
	{
		usage();
		return (0);
	}
	size_t cycle = 0;
	local.players_qnt = 3;
	ft_memset(local.memory, 0, MEM_SIZE);
	get_players(argv, &local);
	load_players_to_memory(&local);
	print_memory( local.memory, cycle++);

	return 0;
}