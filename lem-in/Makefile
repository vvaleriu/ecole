# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2016/07/26 12:40:22 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
I_LINKS = -I./headers -I./libft/header
L_LINKS = -L./libft -lft
RM = rm -rf
vpath %.c ./srcs ./srcs/parser ./srcs/debug ./srcs/tools ./srcs/path \
			./srcs/algo ./srcs/print
vpath %.h headers libft/header
vpath %.a libft
OBJ = $(SRC:%.c=$(O_P)%.o)
O_P = ./obj/
SRC = main.c								\
		read_entry.c						\
		parser.c							\
		parse_room.c						\
		parse_link.c						\
		assert.c							\
		print.c								\
		init.c								\
		tools.c								\
		clean.c								\
		deep_search.c						\
		width_search.c						\
		algo.c								\
		print_mouv.c						\

$(NAME): libft.a $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(I_LINKS) $(L_LINKS)
	@echo Compile done

libft.a: libft.h
	@(cd ./libft/ && make)

$(O_P)%.o: %.c
	@(mkdir -p $(O_P))
	@$(CC) -c $(CFLAGS) $< -o $@ $(I_LINKS)

all: $(NAME)

deb:
	@$(CC) $(CFLAGS) -g3  ./srcs/$(SRC) $(I_LINKS) $(L_LINKS)

clean:
	@$(RM) $(O_P)
	@(cd ./libft/ && make clean)

fclean: clean
	@$(RM) $(NAME)
	@(cd ./libft/ && make fclean)

re: fclean all

.PHONY: clean, re
