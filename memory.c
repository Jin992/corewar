//
// Created by Evgen ARTESHCHUK on 4/23/18.
//

#include "includes/vm.h"

//void	print_memory( u_int8_t *memory)
void init_ncurses(void)
{
 initscr();
 noecho();
 curs_set(0);
 keypad(stdscr, TRUE);
 nodelay(stdscr, TRUE);
 start_color();
}

int	it_is_proces(t_VM *machine, int i)
{
	t_process *tmp;

	tmp = machine->processes;
	while (tmp)
	{
	
		if (tmp->pc == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_memory( t_VM *machine, size_t cycle)
{
	int i;
	int x;
	int y;
	int row_label;

	u_int8_t *memory = machine->memory;
	y = 0;
	i = 0;
	row_label = -64;
	init_ncurses();
	WINDOW* main_field = newwin(100 + 2, 100 + 2, 0, 0);
	wrefresh(main_field);
	// werase(main_field);
	while (y++ < MAX_FIELD_Y)
	{
		x = 0;
		while (x++ < MAX_FIELD_X)
			if (i < MEM_SIZE)
			{
				if (it_is_proces(machine, i) == 1)
				{
					mvwprintw(main_field, y, x, "*");
					i++;
				}
				else
				{
					mvwprintw(main_field, y, x, "%d", machine->memory[i]);
					i++;
				}
			}
	}
	while (wgetch(main_field) != 32)
	;
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
		machine->proceses_live++;
		while (++i < machine->player[j].exec_size + (j * (MEM_SIZE / machine->players_qnt)))
		{
			machine->memory[i] = (u_int8_t) machine->player[j].player_exec[i - (j * (MEM_SIZE / machine->players_qnt))];
			machine->memory_color[i] = (u_int8_t)(j + 1);
		}
		j++;
	}
}