//
// Created by Evgen ARTESHCHUK on 4/23/18.
//

#include "vm.h"

void	print_memory( u_int8_t *memory, size_t cycle)
{
	int i;
	int x;
	int y;
	int row_label;

	y = 0;
	i = 0;
	row_label = -64;
	while (y++ < MAX_FIELD_Y)
	{
		x = 0;
		ft_printf("0x%.4x : ", row_label += MAX_FIELD_Y);
		while (x++ < MAX_FIELD_X)
			if (i < MEM_SIZE)
				ft_printf("%.2x ", memory[i++]);
		ft_printf("\n");
	}
}

void	load_players_to_memory(t_VM *machine)
{
	int i;
	int j;

	j = 0;
	while (j < machine->players_qnt)
	{
		i = j * (MEM_SIZE / machine->players_qnt) - 1;
		proces_create(j, i + 1, machine);
		while (++i < machine->player[j].exec_size + (j * (MEM_SIZE / machine->players_qnt)))
			machine->memory[i] = (u_int8_t)
			machine->player[j].player_exec[i - (j * (MEM_SIZE / machine->players_qnt))];
		j++;
	}
}