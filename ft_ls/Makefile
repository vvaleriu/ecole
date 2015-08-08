# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/01 19:22:50 by vvaleriu          #+#    #+#              #
#    Updated: 2015/08/08 23:25:17 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VPATH specifie un dosser dans lequel effectuer une recherche pour n'importe
# quel type de fichier. Chaque fois au'il ne trouvera pas le fichier dans le
# dossier courantm il cherchera dans un des dossier specifie, dans l'ordre
# specifie

# vpath (minuscule) specifie quels fichiers chercher dans quels dossiers.

NAME = ft_ls
CC = clang-3.5
#CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I./headers -I./libft/header
LIBS = -L./libft -lft
vpath %.c ./srcs ./srcs/files_prop/ ./srcs/display/ ./srcs/tools/ ./srcs/sort/ \
			./srcs/lists/ ./srcs/old/ ./srcs/files_prop/
vpath %.h ./headers ./libft/header
vpath %.a ./libft/
RM = rm -rf
OP = ./.obj/
OBJ = $(SRC:%.c=$(OP)%.o)
SRC = main.c						\
		ft_get_group_name.c			\
		ft_get_file_type.c			\
		ft_get_file_rights.c		\
		ft_get_link_nb.c			\
		ft_get_file_size.c			\
		ft_get_user_name.c			\
		ft_get_last_mod.c			\
		ft_get_file_xattr.c			\
		ft_readlink.c				\
		ft_get_file_min_man.c		\
		set_options.c				\
		ft_count_files.c			\
		ft_difftime.c				\
		init.c 						\
		ls_file.c					\
		create_initial_list.c		\
		get_file_info.c				\
		create_filenames_list.c		\
		del_t_file_list.c			\
		get_file_path_name.c		\
		set_print_prop.c 			\
		reset_print_prop.c 			\
		get_file_in_dir_info.c		\
		print_elem.c				\

all: $(NAME)

$(NAME): libft.a ft_ls.h $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(HEADERS) $(LIBS)

libft.a: libft.h
	@(cd ./libft/ && make)

$(OP)%.o: %.c
	@(mkdir -p $(OP))
	@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

debug: all $(SRCS)
	$(CC) $(CFLAGS) -g -o $@ ./srcs/*.c ./srcs/files_prop/*.c \
	./srcs/display/*.c ./srcs/tools/*.c	./srcs/lists/*.c \
	$(HEADERS) $(LIBS)

clean:
	@$(RM) $(OP)
	@(cd ./libft/ && make clean)

fclean: clean
	$(RM) $(NAME)
	@(cd ./libft/ && make fclean)

re: fclean all
	@(cd ./libft/ && make re)

.PHONY: clean, fclean, re
