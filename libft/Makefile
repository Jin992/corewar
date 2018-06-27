# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/05 14:34:01 by earteshc          #+#    #+#              #
#    Updated: 2018/01/30 15:24:23 by earteshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes


FT_PRINTF = ./ft_printf/char.c ./ft_printf/char_unicode.c ./ft_printf/check_funcs.c ./ft_printf/decimal.c\
./ft_printf/format_write_funcs.c ./ft_printf/ft_itoa_base.c ./ft_printf/ft_printf.c\
./ft_printf/get_var_param.c ./ft_printf/hexadecimal.c \
./ft_printf/octodecimal.c ./ft_printf/output_format_funcs.c ./ft_printf/percent.c\
./ft_printf/pointer.c ./ft_printf/print_type.c ./ft_printf/service_funcs.c ./ft_printf/string.c\
./ft_printf/type_processing.c ./ft_printf/unicode_to_string.c ./ft_printf/unsigned.c ./ft_printf/wrong_var.c\
./ft_printf/cnt_bytes.c ./ft_printf/bonus_star.c ./ft_printf/decimal_parts.c ./ft_printf/float.c

FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
 ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
 ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c\
 ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_new_str_arr.c ft_free_str_arr.c ft_get_words.c\
ft_lstlen.c ft_lstfind.c get_next_line.c ft_realloc.c

OBJ = $(FILES:.c=.o)
FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_OBJ)
	@ar rc  $(NAME) $(OBJ) $(FT_PRINTF_OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(FT_PRINTF_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a

re: fclean all
