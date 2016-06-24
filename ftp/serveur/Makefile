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
BIN_PATH = ../bin/s
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I./headers -I../libs/libft/header -I../common/headers
LIBS = -L../libs/libft -lft
RM = rm -rf
vpath %.c ./srcs ./srcs/execute ./srcs/lexer ./srcs/network ./srcs/tools \
		./srcs/commands ./srcs/send ../common/srcs ./srcs/receive \
		../common/srcs/lexer ../common/srcs/network ../common/srcs/tools
vpath %.h ./headers ../libs/libft/headers ../common/headers
vpath %.a ../libs/
OBJ = $(SRC:%.c=$(OP)%.o)
OP = ./.obj/
SRC = main.c								\
		exe_command.c						\
		get_path.c							\
		execute.c 							\
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
		sv_status.c 						\
		sv_socket_state.c 					\
		sig_handler.c 						\
		sv_prop.c 							\
		bin_cd.c 							\
		bin_help.c							\
		bin_pwd.c 							\
		bin_get.c 							\
		execute_sv.c 						\
		nt_display_send_info.c 				\
		nt_receive_files.c 					\
		nt_receive_info.c 					\
		nt_send_files.c 					\
		nt_send_info.c 						\
		sv_receive_command.c 				\
		sv_receive_prepare.c 				\
		sv_send_prepare.c 					\
		wipe_fd.c							\
		check_port.c 						\
		sv_socket_status.c 					\
		sv_send_message.c 					\

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
