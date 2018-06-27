/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:35:23 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/20 16:35:24 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../corewar_dir/includes/op.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "limits.h"
# include <fcntl.h>

# define FIRST 	1 << 7
# define SECOND 1 << 6
# define THIRD 	1 << 5
# define FOURTH 1 << 4
# define FIFTH 	1 << 3
# define SIXTH 	1 << 2

# define EMPTY			0
# define NAME_COOMENT	1
# define OP_CODE		2
# define START_QUOTE	3
# define END_QUOTE		4
# define DOUBLE_QUOTE	5

typedef struct		s_code
{
	char			*label;
	char			way[4];
	char			op_code[6];

	int				reg[3];

	char			*dir_1;
	char			*dir_2;
	char			*dir_3;

	char			*ind_1;
	char			*ind_2;
	char			*ind_3;

	int				line;
	int				op_num;
	int				codage;
	int				label_size;
	int				label_position;
	int				opcode_position;

	struct s_code	*next;
	struct s_code	*prev;
}					t_code;

typedef struct		s_data
{
	char			*line;
	int				num_line;
	int				is_readed;
	int				type_line;

	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct		s_labels
{
	char			*label;
	int				opcode_position;

	struct s_labels	*next;
	struct s_labels	*prev;
}					t_labels;

typedef struct		s_instr
{
	char			op_code_v[6];
	char			argum[13];
}					t_instr;

typedef struct		s_valid
{
	char			all_chars[45];
	int				find_name;
	int				find_comment;
	t_instr			example_instr[16];
}					t_valid;

void				read_name(t_data *data, t_header *asmus);
void				ft_build_valid(t_valid *valid);
void				read_comment(t_data *data, t_header *asmus);
void				parsing_data(t_data *data, t_valid *valid);
t_code				*exec_code(t_data *data, t_code *code,
						t_labels **l_l, int i);
int					ft_isnoempty(char *line, char **label);
void				ft_clean_map(char **map);
unsigned char		*conv_bytes(t_code *code, t_header *asmus,
						t_labels *labels_list);
int					conv_ins(t_code *code, unsigned char *ins,
						t_labels *labels_list);
void				ft_error_exit(int type, int num_line,
						int num_char, char *str);
unsigned int		reverse_b(unsigned int num, int size);
void				ft_struct_free(t_code *code);
void				give_op_labels(t_labels *labels_list,
						t_code *code, int bytes_num);
void				ft_parsing_invalid_symbols(t_data *data, t_valid *valid);
void				ft_parsing_instructions(t_data *data, t_valid *valid);
void				ft_search_arg(t_data *data, t_valid *valid,
						int *n_u, char *argm);
char				*ft_find_instr(char *line);
t_data				*create_data(int fd, int i, int u);
void				conv_codage(t_code *code);
int					ft_take_position(t_code *code, char *dir,
						t_labels *labels_list);
void				ft_direct_vc(t_code *code, int tmp,
						unsigned char *ins, int i);
void				build_arguments(char *line, t_code *tmp, int u);
void				give_label_position(t_code *code, int pos);
t_labels			*ft_label_cr(t_labels **labels_t, char *label,
						t_labels *l_list);
void				give_op_num(t_code *tmp);
void				ft_data_labels_free(t_data *data, t_labels *labels_list);

#endif
