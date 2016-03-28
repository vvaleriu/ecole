# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2016/03/28 10:11:23 by vvaleriu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CC = gcc
CFLAGS = -Wall -Wextra -Werror
I_LINKS = -I./headers -I./libft/header
L_LINKS = -L./libft -lft -ltermcap
RM = rm -rf
vpath %.c ./srcs ./srcs/builtins ./srcs/init/ ./srcs/lexer/ ./srcs/tools/ \
			./srcs/execute  ./srcs/parser ./srcs/signals ./srcs/termcaps/ \
			./srcs/termcaps/key_handlers ./srcs/termcaps/setup \
			./srcs/completion \
			./srcs/termcaps/printing ./srcs/termcaps/tools ./srcs/inputs
vpath %.h includes libft/header
vpath %.a libft
OBJ = $(SRC:%.c=$(O_P)%.o)
O_P = ./obj/
SRC = main.c					\
		init_function.c			\
	  	is_text.c				\
	  	lexer.c					\
		lex_semicon.c			\
		lex_small.c				\
		lex_big.c				\
		lex_pipe.c				\
		lex_space.c				\
		lex_and.c				\
		lex_char.c				\
		parser.c				\
		exe_command.c			\
		get_path.c				\
		ft_cd.c					\
		ft_env.c				\
		ft_setenv.c				\
		ft_exit.c				\
		ft_unsetenv.c			\
		ft_copy_env.c			\
		create_tokens.c			\
		execute_tree.c			\
		free_all_list.c 		\
		clean_tree.c			\
		clean_env.c				\
		sig_catcher.c			\
		sig_handler.c			\
		get_env_value.c			\
		find_env.c              \
		init_terminal.c			\
		terminal_modes.c		\
		load_term_prop.c		\
		set_str_cap.c			\
		go_background.c			\
		go_foreground.c			\
		restore_terminal.c		\
		get_instance.c			\
		clean_term_conf.c		\
		read_key.c				\
		update_win_size.c 		\
		ft_putstr_cursor.c		\
		ft_putchar_cursor.c		\
		ft_putstr_fixed.c		\
		ft_putchar_fixed.c		\
		move_cursor.c			\
		move_cursor2.c			\
		putchar_int.c 			\
		move_to.c				\
		return_command.c 		\
		build_line.c			\
		history.c				\
		setup_line_struct.c		\
		cursor_pos.c			\
		debug_termcaps.c		\
		clear_screen.c			\
		copy_paste.c			\
		del_hist_el.c			\
		position_tracker.c		\
		is_fd_aggregation.c		\
		token_tools.c			\
		exe_semi.c				\
		exe_and.c				\
		exe_or.c				\
		exe_pipe.c				\
		exe_redir_in.c			\
		exe_redir_out.c			\
		is_builtin.c			\
		fds_tools.c				\
		completion.c			\
		exe_list.c				\
		files_list.c			\

$(NAME): libft.a $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(I_LINKS) $(L_LINKS)
	@echo Compile done

libft.a: libft.h
	@(cd ./libft/ && make)

$(O_P)%.o: %.c
	@(mkdir -p $(O_P))
	@$(CC) -c $(CFLAGS) $< -o $@ $(I_LINKS)

all: $(NAME)

clean:
	@$(RM) $(O_P)
	@(cd ./libft/ && make clean)

fclean: clean
	@$(RM) $(NAME)
	@(cd ./libft/ && make fclean)

re: fclean all

.PHONY: clean, re,
