# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:22:58 by olaurine          #+#    #+#              #
#    Updated: 2020/07/28 23:02:35 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	ft_printf.c \
		ft_parser.c \
		ft_pf_utils.c \
		ft_processor.c \
		ft_pf_char.c \
		ft_pf_string.c \
		ft_pf_pointer.c \
		ft_pf_int.c \
		ft_pf_x.c
OBJ = $(patsubst %.c,%.o,$(SRC))
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

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
