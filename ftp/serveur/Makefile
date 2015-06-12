# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2015/06/12 13:23:03 by vvaleriu         ###   ########.fr        #
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
		exe_command.c						\
		get_path.c							\
		command_checker.c					\
		lex_char.c							\
		lex_space.c							\
		lexer.c								\
		init.c								\
		sv_accept.c 						\
		sv_create.c 						\
		clean_fd.c 							\
		error_checker.c 					\
		pterr.c 							\
		usage.c 							\
		main_loop.c 						\
		sv_kill.c 							\
		max.c 								\
		init_fds.c 							\
		check_fds.c 						\
		select_fds.c 						\
		ft_read.c 							\
		ft_write.c 							\
		sv_status.c 						\
		sv_socket_state.c 					\
		sig_handler.c 						\

all: $(NAME)

deb: 
	@(sh deb.sh)

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
