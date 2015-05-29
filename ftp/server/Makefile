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

NAME = server
BIN_PATH = ../bin
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I./headers -I../libs/libft/headers
LIBS = -L../libs -lft
RM = rm -rf
vpath %.c ./srcs
vpath %.h ./headers ../libs/libft/headers
vpath %.a ../libs/
OBJ = $(SRC:%.c=$(OP)%.o)
OP = ./.obj/
SRC = main.c								\
		errors.c							\
		network.c							\

all: $(NAME)

deb: 
	gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

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
