# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earteshc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 11:46:50 by earteshc          #+#    #+#              #
#    Updated: 2018/05/10 11:46:53 by earteshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

NAME1 = asm

HEAD = corewar_dir/vm.h\

SRC = corewar_dir/main.c

PROC = corewar_dir/processor/processor_create.c\
	corewar_dir/processor/processor_clone.c\
	corewar_dir/processor/proccessor_kill_this.c\
	corewar_dir/processor/processor.c\
	corewar_dir/processor/processor_2.c\
	corewar_dir/processor/proccessor_3.c

VISU = corewar_dir/visual/corewar.c\
	corewar_dir/visual/create.c\
	corewar_dir/visual/start.c\
	corewar_dir/visual/get_mous.c\
	corewar_dir/visual/if_this_op.c\
	corewar_dir/visual/get_mouse_2.c\
	corewar_dir/visual/create_2.c

OP = corewar_dir/Operations/aff_operation.c\
	corewar_dir/Operations/and_operation.c\
	corewar_dir/Operations/fork_operation.c\
	corewar_dir/Operations/ld_operation.c\
	corewar_dir/Operations/ldi_operation.c\
	corewar_dir/Operations/lfork_operation.c\
	corewar_dir/Operations/lld_operation.c\
	corewar_dir/Operations/lldi_operation.c\
	corewar_dir/Operations/or_operation.c\
	corewar_dir/Operations/st_operation.c\
	corewar_dir/Operations/sti_operation.c\
	corewar_dir/Operations/sub_operation.c\
	corewar_dir/Operations/xor_operation.c\
	corewar_dir/Operations/zjmp_operation.c\
	corewar_dir/Operations/add_operation.c\
	corewar_dir/Operations/live_operation.c\
	corewar_dir/Operations/get_bytes.c\
	corewar_dir/Operations/get_idx_mod.c\
	corewar_dir/Operations/get_operand.c\
	corewar_dir/Operations/move_pc.c \
	corewar_dir/Operations/check_octal.c

DATA = corewar_dir/data/error.c\
		corewar_dir/data/player.c\
		corewar_dir/data/memory.c\
		corewar_dir/data/validate_data.c\
		corewar_dir/data/validate_data_2.c

ASM = ASM_DIR/main.c \
		ASM_DIR/name_comment.c \
		ASM_DIR/exec_code.c \
		ASM_DIR/exec_code_2.c \
		ASM_DIR/label_create.c \
		ASM_DIR/conv_bytes.c \
		ASM_DIR/convert_instruction.c \
		ASM_DIR/convert_instruction_2.c \
		ASM_DIR/all_free.c \
		ASM_DIR/parsing_data.c \
		ASM_DIR/labels.c \
		ASM_DIR/parsing_data_1.c \
		ASM_DIR/validation_builder.c \
		ASM_DIR/parsing_instruction.c \
		ASM_DIR/parsing_instruction_2.c \
		ASM_DIR/data_create.c	

LIBFT = libft

OBJ = $(SRC:.c=.o)

OPJ = $(OP:.c=.o)

VISUJ = $(VISU:.c=.o)

PROCJ = $(PROC:.c=.o)

DATAJ = $(DATA:.c=.o)

ASMJ = $(ASM:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(OPJ) $(VISUJ) $(PROCJ) $(DATAJ) $(ASMJ)
	make -C $(LIBFT)
	$(CC) -g $(CFLAGS) $(OBJ) $(OPJ) $(VISUJ) $(PROCJ) $(DATAJ) -L $(LIBFT) -lft -o $(NAME) -lncurses
	$(CC) -g $(CFLAGS) $(ASMJ) -L $(LIBFT) -lft -o $(NAME1) 

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(OPJ) $(VISUJ) $(PROCJ) $(DATAJ) $(ASMJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME1)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean