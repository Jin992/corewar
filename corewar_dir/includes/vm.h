/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:19:05 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 14:19:07 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdbool.h>
# include <fcntl.h>
# include <ncurses.h>
# include "op.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include "operations.h"

# define MAX_FIELD_X	64
# define MAX_FIELD_Y	64
# define F_PAIR(x)((x & 0xFF) << 24)
# define S_PAIR(x)((x & 0xFF00) << 8)
# define T_PAIR(x)((x & 0xFF0000) >> 8)
# define FR_PAIR(x)((x & 0xFF000000) >> 24)
# define REVERSE_4_BYTES(x) (F_PAIR(x)| S_PAIR(x) | T_PAIR(x) | FR_PAIR(x))
# define REVERSE_2_BYTES(x) (((x) << 8) | ((x) >> 8))
# define SPEED_DELTA 	20000
# define NORMAL_SPEED 	50000
# define SLOWEST_SPEED 	200000
# define MAX_SLOTS 		10

typedef struct s_players	t_players;
typedef struct s_process	t_process;
typedef struct s_vm			t_vm;

struct						s_process
{
	int						pc;
	int						value;
	int						timer;
	int						color;
	int						im_alive;
	void					(*op)(t_vm *vm, t_process *cur);
	u_int8_t				reg[REG_NUMBER][REG_SIZE];
	bool					carry;
	struct s_process		*next;
	struct s_process		*prev;
};

struct						s_players
{
	int						player_nbr;
	int						last_live;
	int						live_cur_period;
	int32_t					exec_size;
	u_int8_t				magic[4];
	char					name[PROG_NAME_LENGTH];
	char					comment[COMMENT_LENGTH];
	unsigned char			player_exec[MEM_SIZE / 6];
};

struct						s_vm
{
	int						aff;
	int						res;
	int						visual;
	int						e_flag;
	int						dump;
	int						cycle;
	int						wait;
	int						proceses_live;
	int						cycle_limit;
	int						players_qnt;
	int						cycle_to_die;
	int						period;
	int						max_check;
	int						space;
	int						nbr_live;
	int						winner;
	int						max_checks;
	int						empty[4];
	int						speed;
	u_int8_t				memory[MEM_SIZE];
	u_int8_t				memory_color[MEM_SIZE];
	WINDOW					*menu;
	WINDOW					*main_field;
	WINDOW					*help_menu;
	WINDOW					*help_menu_2;
	WINDOW					*lite;
	t_process				*processes;
	t_process				*print_reg;
	t_players				player[4];
};

void						processor_wrong_id(t_process *tmp);
void						processor_cycle(t_process *tmp, t_vm *vm);
void						processor_check(t_vm *vm);
void						processor_create(int color, int pc, t_vm *vm);
void						processor(t_vm *vm);
void						processor_clone(t_vm *vm, t_process *clone, int pc);
void						proccessor_kill_this(t_vm *vm);
void						processor_normal(t_vm *vm);
void						processor_visual(t_vm *vm);
void						processor_e_mod(t_vm *vm);
void						dump_memmory(t_vm *vm);
void						del_win(t_vm *vm);
void						winner(t_vm *vm);
void						proccessor_kill_all(t_process **begin_list);
void						print_info_players(t_vm *vm);
void						get_players(char *str, t_vm *vm, int cnt, int fd);
void						load_players_to_memory(t_vm *vm);
int							find_core_file(char *str);
int							parse_flags(char **argv, t_vm *local);
int							usage();
void						get_key(t_vm *vm);
void						if_this_op(t_vm *vm, int cord);
void						get_mouse(t_vm *vm);
void						print_mem(t_vm *vm);
void						ft_init_color(void);
void						ft_start_ncurses(t_vm *vm);
void						ft_procesing_ncurses(t_vm *vm);
void						ft_create_frame(void);
void						ft_create_window(t_vm *vm);
void						ft_create_menu(t_vm *vm);
void						players_data(t_vm *vm, int *y);
void						ft_print_name(t_vm *vm, int i, int *y);
void						ft_create_map(t_vm *vm);
void						get_key(t_vm *vm);
void						get_key_2(t_vm *vm);
void						print_winner(t_vm *vm);
int							main(int argc, char **argv);
void						procesing_step_by_step(t_vm *vm);
void						processor_step_by_step(t_vm *vm);
void						print_register(t_vm *vm);

#endif
