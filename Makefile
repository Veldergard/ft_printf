# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:22:58 by olaurine          #+#    #+#              #
#    Updated: 2020/07/20 01:47:19 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	base/ft_printf.c \
		parser/ft_parser.c \
		parser/ft_flags_parse.c \
		parser/ft_width_parse.c \
		parser/ft_precision_parse.c \
		parser/ft_type_parse.c
OBJ = $(patsubst %.c,%.o,$(SRC))
LIBFT = libft/libft.a
HEADERS = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -g

.PHONY: all clean fclean re

all: libft/libft.a $(NAME)

libft/libft.a:
	make all -C libft

test: $(OBJ)
	$(CC) $(CFLAGS) main.c libftprintf.a -o test

$(NAME): $(OBJ)
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	/bin/rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME)

re: fclean all
