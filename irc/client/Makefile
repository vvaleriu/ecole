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

NAME = client
BIN_PATH = ../bin/c/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I./headers -I../libs/libft/headers  -I../common/headers
LIBS = -L../libs -lft
RM = rm -rf
vpath %.c ./srcs ./srcs/network ./srcs/tools ./srcs/commands ../common/srcs \
			./srcs/send ./srcs/receive ../common/srcs/lexer \
			../common/srcs/network ../common/srcs/tools
vpath %.h headers ../libs/libft/headers ../common/headers
vpath %.a ../libs/
OBJ = $(SRC:%.c=$(OP)%.o)
OP = ./.obj/
SRC = main.c								\
		init.c 								\
		cl_connect.c						\
		cl_kill.c 							\
		usage.c 							\
		pterr.c 							\
		error_checker.c 					\
		init_fds.c 							\
		cl_send_command.c					\
		cl_send_prepare.c 					\
		cl_select.c 						\
		check_fds.c 						\
		main_loop.c 						\
		cl_receive_prepare.c 				\
		cl_receive_output.c 				\
		sig_handler.c 						\
		lex_char.c							\
		lex_space.c							\
		lexer.c								\
		nt_display_send_info.c 				\
		nt_receive_files.c 					\
		nt_receive_info.c 					\
		nt_send_files.c 					\
		nt_send_info.c 						\
		clean_fd.c 							\
		wipe_fd.c 							\
		check_port.c 						\
		is_client_side_command.c 			\
		exe_command.c 						\
		get_path.c 							\

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
