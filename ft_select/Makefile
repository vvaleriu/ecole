# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2016/03/31 20:39:42 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
CFLAGS = -Wall -Wextra -Werror
I_LINKS = -I./headers -I./libft/header
L_LINKS = -L./libft -lft -ltermcap
RM = rm -rf
vpath %.c ./srcs ./srcs/key_handlers ./srcs/sig_handlers \
		./srcs/term_setup ./srcs/tools ./srcs/printing
vpath %.h headers libft/header
vpath %.a libft
OBJ = $(SRC:%.c=$(O_P)%.o)
O_P = ./obj/
SRC = main.c						\
		init_terminal.c 			\
		load_term_prop.c			\
		resize_list.c				\
		sig_catcher.c				\
		get_key.c					\
		change_term_attr.c			\
		print_small_size_error.c	\
		print_list.c				\
		putchar_int.c				\
		set_str_cap.c 				\
		new_item.c					\
		build_list.c				\
		deb_list.c					\
		deb_item.c					\
		del_list_elem.c				\
		print_item.c				\
		move_to.c					\
		get_instance.c				\
		exit_clean.c				\
		move_cursor.c				\
		close_program.c				\
		delete_item.c				\
		select_item.c				\
		go_background.c				\
		go_foreground.c

$(NAME): libft.a $(OBJ) ft_select.h
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