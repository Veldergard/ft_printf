# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:22:58 by olaurine          #+#    #+#              #
#    Updated: 2020/07/27 20:01:59 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	src/ft_printf.c \
		src/ft_parser.c \
		src/ft_pf_utils.c \
		src/ft_processor.c \
		src/ft_pf_char.c \
		src/ft_pf_string.c \
		src/ft_pf_pointer.c \
		src/ft_pf_int.c \
		src/ft_pf_x.c
OBJ = $(patsubst %.c,%.o,$(SRC))
LIBFT = libft/libft.a
HEADERS = includes/ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -g

.PHONY: all clean fclean re

all: libft/libft.a $(NAME)

libft/libft.a:
	make all -C libft

$(NAME): $(OBJ)
	@[ -f $@ ] || cp libft/libft.a $(NAME)
	ar rcs $(NAME) $?

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	/bin/rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME)

re: fclean all
