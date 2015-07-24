# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2015/03/04 14:15:28 by vvaleriu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell_2
CC = clang-3.5
CFLAGS = -Wall -Wextra -Werror
I_LINKS = -I./headers -I./libft/header
L_LINKS = -L./libft -lft
RM = rm -rf
vpath %.c ./srcs ./srcs/builtins ./srcs/init/ ./srcs/lexer/ ./srcs/tools/ \
			./srcs/execute ./srcs/parser
vpath %.h includes libft/header
vpath %.a libft
OBJ = $(SRC:%.c=$(O_P)%.o)
O_P = ./obj/
SRC = main.c					\
		init_function.c			\
	  	is_space.c				\
	  	is_text.c				\
	  	is_operator.c			\
	  	lexer.c					\
		lex_semicon.c			\
		lex_small.c				\
		lex_big.c				\
		lex_pipe.c				\
		lex_space.c				\
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
		exe_func.c				\
		free_all_list.c 		\
		clean_tree.c			\
		clean_env.c				\
		signals_handlers.c		\
		get_env_value.c			\
		find_env.c              \

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
