#include "includes/vm.h"

static void	init_vm(t_VM *local, int argc)
{
	local->processes = NULL;
	local->proceses_live = 0;
	local->cycle_to_die = CYCLE_TO_DIE;
	local->period = CYCLE_TO_DIE;
	local->max_check = 0;
	local->visual = 0;
	local->lite = 0;
	local->players_qnt = 0;
}

int main(int argc, char **argv)
{
	t_VM	local;

	init_vm(&local, argc);
	if (!(parse_flags(argc, argv, &local)))
		return (0);
	ft_memset(local.memory, 0, MEM_SIZE);
	ft_memset(local.memory_color, 0, MEM_SIZE);
	get_players(argv, &local);
	load_players_to_memory(&local);
	if (local.players_qnt == 0)
		return (0);
	if (local.visual == 0)
		processor_normal(&local);
	else
		processor_visual(&local);
	return (0);
}

