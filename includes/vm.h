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
#define		MAX_FIELD_X		64
#define		MAX_FIELD_Y		64
#define REVERSE_4_BYTES(x) ((((x) & 0xFF) << 24) | ((((x) & 0xFF00) << 8)) | ((((x) & 0xFF0000) >> 8)) | (((x) & 0xFF000000) >> 24))
#define REVERSE_2_BYTES(x) (((x) << 8) | ((x) >> 8))


//Operations Opcode
#define LIVE 1
#define LD 2
#define	ST 3
#define ADD 4
#define SUB 5
#define AND 6
#define OR 7
#define XOR 8
#define ZJMP 9
#define LDI 10
#define STI 11
#define FORK 12
#define LLD 13
#define LLDI 14
#define LFORK 15
#define AFF 16

typedef struct	s_process
{
	int					pc;
	int 				timer;
	void				(*op)();
	int 				color;
	char				reg[REG_NUMBER][REG_SIZE];
	bool				carry;
	struct s_process	*next;
}				t_process;

typedef struct	s_player
{
	int					player_nbr;
	int					last_live;
	int					live_cur_period;
	int32_t				exec_size;
	char				magic[8];
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	unsigned char 		player_exec[MEM_SIZE / 6];
}				t_players;

typedef struct	s_VM
{
	int					cycle;
	int					cycle_limit;
	int					players_qnt;
	int					cycle_to_die;
	int					cycle_delta;
	int					nbr_live;
	int 				time;
	int					max_checks;
	u_int8_t 			memory[MEM_SIZE];
	u_int8_t 			memory_color[MEM_SIZE];

	t_process			*processes;
	t_players			player[4];
}				t_VM;

void	get_players(char **argv, t_VM *machine);
void	print_memory( u_int8_t *memory, size_t cycle);

void	load_players_to_memory(t_VM *machine);
void	usage();

void	proces_create(int color, int pc, t_VM *machine);
void	processor(t_VM *machine);
#endif //COREWAR_VM_H
