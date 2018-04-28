//
// Created by Evgen ARTESHCHUK on 4/23/18.
//

#include "includes/vm.h"

void	load_players_to_memory(t_VM *machine)
{
	int i;
	int j;

	j = 0;
	while (j < machine->players_qnt)
	{
		i = j * (MEM_SIZE / machine->players_qnt) - 1;
		processor_create(j, i + 1, machine);
		machine->proceses_live++;
		while (++i < machine->player[j].exec_size + (j * (MEM_SIZE / machine->players_qnt)))
		{
			machine->memory[i] = (u_int8_t) machine->player[j].player_exec[i - (j * (MEM_SIZE / machine->players_qnt))];
			machine->memory_color[i] = (u_int8_t)(j + 1);
		}
		j++;
	}
}