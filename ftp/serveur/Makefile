# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2015/02/02 11:36:54 by vvaleriu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serveur
BIN_PATH = ../bin
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I./headers -I../libs/libft/headers
LIBS = -L../libs -lft
RM = rm -rf
vpath %.c ./srcs ./srcs/execute ./srcs/commands ./srcs/lexer ./srcs/network \
			./srcs/tools
vpath %.h ./headers ../libs/libft/headers
vpath %.a ../libs/
OBJ = $(SRC:%.c=$(OP)%.o)
OP = ./.obj/
SRC = main.c								\
		errors.c							\
		network.c							\
		client_input.c						\
		exe_command.c						\
		get_path.c							\
		command_checker.c					\
		lex_char.c							\
		lex_space.c							\
		lexer.c								\
		socket.c							\
		init.c								\

all: $(NAME)

deb: 
	gcc -g3 -I./libs/libft/headers -I./libs/libft/headers -L./libs/libft/ -lft ./srcs/*.c ./srcs/execute/*.c ./srcs/commands/*.c ./srcs/lexer/*.c

hallah:
	gcc -g3 -I../libs/libft/headers -I./headers  -L../libs -lft ./srcs/client_input.c ./srcs/errors.c ./srcs/main.c ./srcs/network.c ./srcs/execute/command_checker.c ./srcs/execute/exe_command.c ./srcs/execute/get_path.c  ./srcs/lexer/lex_char.c ./srcs/lexer/lex_space.c ./srcs/lexer/lexer.c
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(BIN_PATH)/$@ $(OBJ) $(HEADERS) $(LIBS)

$(OP)%.o: %.c
	@(mkdir -p $(OP))
	@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

clean:
	@$(RM) $(OP)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re
