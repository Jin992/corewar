//
// Created by Evgen ARTESHCHUK on 4/21/18.
//

#ifndef COREWAR_VM_H
#define COREWAR_VM_H

#include <stdbool.h>
#include "op.h"
#include <fcntl.h>
#include "../lib/includes/libft.h"
#include "../lib/includes/ft_printf.h"
#include "operations.h"
#include <ncurses.h>

#define		MAX_FIELD_X		64
#define		MAX_FIELD_Y		64
#define REVERSE_4_BYTES(x) ((((x) & 0xFF) << 24) | ((((x) & 0xFF00) << 8)) | ((((x) & 0xFF0000) >> 8)) | (((x) & 0xFF000000) >> 24))
#define REVERSE_2_BYTES(x) (((x) << 8) | ((x) >> 8))

typedef struct	s_players t_players;
typedef struct	s_process t_process;
typedef struct	s_VM 		t_VM;

struct					s_process
{
	int					pc; // їхне положення на карті
	int 				timer; // цикли дов викоання дії
	void				(*op)(t_VM *machine, t_process *cur); // operation
	int 				color; // хто створив каретку і коли належить поточна operation
	u_int8_t			reg[REG_NUMBER][REG_SIZE];
	int 				im_alive;
	bool				carry;
	struct s_process	*next;
	struct s_process	*prev;
};

struct					s_players
{
	int					player_nbr;
	int					last_live;
	int					live_cur_period;
	int32_t				exec_size;
	char				magic[8];
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	unsigned char 		player_exec[MEM_SIZE / 6];
};

struct					s_VM
{
	int					cycle;
	int 				proceses_live;
	int					cycle_limit;
	int					players_qnt;
	int					cycle_to_die;
	int 				period;
	int 				max_check;
	int					nbr_live;
	int 				winner; // Хто останній сказав живий
	int 				number_of_processes; //поточнка кількість процесів
	int					max_checks;
	u_int8_t 			memory[MEM_SIZE]; // память(карта)
	u_int8_t 			memory_color[MEM_SIZE]; // кому яка клітинка належить(0 нікого)
	WINDOW				*menu;
	WINDOW				*main_field;
	t_process			*processes; // ПРОцеси які зараз діють(каретки)
	t_players			player[4];
};

void	    get_players(char **argv, t_VM *machine);
void	    print_memory( t_VM *machine, size_t cycle);
void	    load_players_to_memory(t_VM *machine);
void        usage();
void        init_ncurses(t_VM *machine);
void		proces_create(int color, int pc, t_VM *machine);
void		processor(t_VM *machine);
void		proces_clone(t_VM *machine, t_process *clone, int pc);
void		kill_this_proccess(t_process **kill_me);
#endif //COREWAR_VM_H
