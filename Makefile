NAME = VM

HEAD = vm.h\

SRC = main.c

PROC = processor/processor_create.c\
	processor/processor_clone.c\
	processor/proccessor_kill_this.c\
	processor/processor.c\
	processor/processor_2.c

VISU = visual/corewar.c\
	visual/create.c\
	visual/start.c\
	visual/get_mous.c

OP = Operations/aff_operation.c\
	Operations/and_operation.c\
	Operations/fork_operation.c\
	Operations/ld_operation.c\
	Operations/ldi_operation.c\
	Operations/lfork_operation.c\
	Operations/lld_operation.c\
	Operations/lldi_operation.c\
	Operations/or_operation.c\
	Operations/st_operation.c\
	Operations/sti_operation.c\
	Operations/sub_operation.c\
	Operations/xor_operation.c\
	Operations/zjmp_operation.c\
	Operations/add_operation.c\
	Operations/live_operation.c\
	Operations/get_bytes.c

DATA = data/error.c\
		data/player.c\
		data/memory.c\
		data/validate_data.c\

LIBFT = lib/

OBJ = $(SRC:.c=.o)

OPJ = $(OP:.c=.o)

VISUJ = $(VISU:.c=.o)

PROCJ = $(PROC:.c=.o)

DATAJ = $(DATA:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(OPJ) $(VISUJ) $(PROCJ) $(DATAJ)
	make -C $(LIBFT)
	$(CC) -g $(FLAGS) $(OBJ) $(OPJ) $(VISUJ) $(PROCJ) $(DATAJ) -L $(LIBFT) -lft -o $(NAME) -lncurses

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(OPJ) $(VISUJ) $(PROCJ) $(DATAJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean