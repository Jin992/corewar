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
#define 	REVERSE_4_BYTES(x) ((((x) & 0xFF) << 24) | ((((x) & 0xFF00) << 8)) | ((((x) & 0xFF0000) >> 8)) | (((x) & 0xFF000000) >> 24))
#define 	REVERSE_2_BYTES(x) (((x) << 8) | ((x) >> 8))

typedef struct	s_players t_players;
typedef struct	s_process t_process;
typedef struct	s_VM 		t_VM;

struct					s_process
{
	int					pc;
	int 				timer;
	void				(*op)(t_VM *vm, t_process *cur);
	int 				color;
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
	u_int8_t 			magic[4];
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
	int 				space;
	int					nbr_live;
	int 				winner; 
	int					max_checks;
	int 				visual;
	int 				aff;
	int 				empty[4];
	int 				dump;
	int 				wait;
	u_int8_t 			memory[MEM_SIZE];
	u_int8_t 			memory_color[MEM_SIZE];
	WINDOW				*menu;
	WINDOW				*main_field;
	WINDOW				*help_menu;
	WINDOW 				*lite;
	t_process			*processes;
	t_process			*print_reg;
	t_players			player[4];
};

//processes
void		processor_wrong__id(t_process *tmp);
void		processor_cycle(t_process *tmp, t_VM *vm);
void 		processor_check(t_VM *vm);
void		processor_create(int color, int pc, t_VM *vm);
void		processor(t_VM *vm);
void		processor_clone(t_VM *vm, t_process *clone, int pc);
void			proccessor_kill_this(t_process **kill_me);
void		processor_normal(t_VM *vm);
void		processor_visual(t_VM *vm);
void		dump_memmory(t_VM *vm);
void		del_win(t_VM *vm);
void		winner(t_VM *vm);

//main
void		get_players(char *str, t_VM *vm, int cnt, int fd);
void	    print_memory( t_VM *vm, size_t cycle);
void	    load_players_to_memory(t_VM *vm);

//validate
int			find_core_file(char *str);
int			parse_flags(int argc, char **argv, t_VM *local);
int        	usage();


void		get_key(t_VM *vm);
//visual
void	if_this_op(t_VM *vm, int cord);
void	get_mouse(t_VM *vm);
void	print_mem( u_int8_t *memory);
void	ft_init_color(void);
void	ft_start_ncurses(t_VM *vm);
void	ft_procesing_ncurses(t_VM *vm);
void	ft_create_frame(t_VM *vm);
void	ft_create_window(t_VM *vm);
void	ft_create_menu(t_VM *vm);
void	players_data(t_VM *vm, int *y);
void	ft_print_name(t_VM *vm, int i, int *y);
void	ft_create_map(t_VM *vm);
void		get_key(t_VM *vm);
void		get_key_2(t_VM *vm);

void	procesing_step_by_step(t_VM *vm);
void	processor_step_by_step(t_VM *vm);
#endif //COREWAR_VM_H
