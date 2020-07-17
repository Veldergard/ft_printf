# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:22:58 by olaurine          #+#    #+#              #
#    Updated: 2020/07/16 20:03:33 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.o

SRC = ft_printf.c main.c

HEADERS = ft_printf.h

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@echo "clean"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(NAME) removed"

re: fclean all
