NAME = VM

HEAD = vm.h\


SRC = main.c\
		error.c\
		memory.c\
		player.c\
		proces_create.c\
		processor.c\


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

		
LIBFT = lib/

OBJ = $(SRC:.c=.o)

OPJ = $(OP:.c=.o)

FLAGS = 

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(OPJ)
	make -C $(LIBFT)
	$(CC) -g $(FLAGS) $(OBJ) $(OP) -L $(LIBFT) -lft -o $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(OP)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean