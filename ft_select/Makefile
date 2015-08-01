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

NAME = ft_select
CC = clang-3.5
CFLAGS = -Wall -Wextra -Werror
I_LINKS = -I./headers -I./libft/header
L_LINKS = -L./libft -lft -ltermcap
RM = rm -rf
vpath %.c ./srcs ./srcs/key_handlers ./srcs/sig_handlers ./srcs/init \
		./srcs/term_setup ./srcs/tools
vpath %.h includes libft/header
vpath %.a libft
OBJ = $(SRC:%.c=$(O_P)%.o)
O_P = ./obj/
SRC = main.c					\
		init_terminal.c 		\
		load_term_prop.c		\
		get_screen_size.c		\
		sig_handler.c			\
		sig_catcher.c			\
		get_key.c				\
		handle_arrow.c 			\
		handle_return.c			\
		change_term_attr.c		\
		print_list.c			\
		putchar_int.c			\
		toggle_str_cap.c 		\
		new_item.c				\
		build_list.c			\

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
