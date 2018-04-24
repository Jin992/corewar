#include <stdio.h>
#include "vm.h"

static void (*operations[16])() = {&add_operation, &aff_operation, &and_operation,
									&fork_operation, &ld_operation, &ldi_operation, 
									&lfork_operation, &live_operation, &lld_operation,
									&lldi_operation, &or_operation, &st_operation,
									&sti_operation, &sub_operation, &xor_operation, 
									&zjmp_operation};

void	move_procese(t_process *tmp, t_VM *machine)
{
	if (tmp->timer == -1)
	{
		if (machine->memory[tmp->pc] > 1 && machine->memory[tmp->pc] < 16)
			tmp->op = operations[machine->memory[tmp->pc++]];
		else
			tmp->pc++;
		tmp->timer = MEM_SIZE - 100;
	}
	else if (tmp->timer > 0)
		tmp->timer--;
	else
	{
		tmp->timer = -1;
		tmp->op();
	}
}

void	vm_init(t_VM *machine)
{
	t_process tmp;

	tmp.pc = 0;
	tmp.timer = -1;
	int time = 0;
	while (time < MEM_SIZE)
	{
		move_procese(&tmp, machine);
		time++;
	}
	ft_printf("\n");
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
	ft_memset(local.memory_color, 0, MEM_SIZE);
	get_players(argv, &local);
	load_players_to_memory(&local);
	vm_init(&local);
//	print_memory(local.memory, cycle++);

	return 0;
}