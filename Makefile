# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:22:58 by olaurine          #+#    #+#              #
#    Updated: 2020/07/21 18:31:22 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	base/ft_printf.c \
		base/ft_parser.c \
		processor/ft_processor.c \
		processor/ft_pf_char.c \
		processor/ft_pf_string.c \
		processor/ft_pf_pointer.c
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
