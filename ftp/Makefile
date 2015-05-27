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

NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
I_LINKS = -I./includes -I./libft/includes
L_LINKS = -L./libft -lftprintf
RM = rm -rf
vpath %.c ./srcs
vpath %.h includes libft/includes
vpath %.a libft
OBJ = $(SRC:%.c=$(OP)%.o)
OP = ./.obj/
SRC = main.c					\

all: $(NAME)

deb: 
	gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

scan: 
	scanbuild gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

$(NAME): libftprintf.a $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(I_LINKS) $(L_LINKS)
	@echo Compile done

libftprintf.a: libft.h
	@(cd ./libft/ && make)

$(OP)%.o: %.c
	@(mkdir -p $(OP))
	@$(CC) -c $(CFLAGS) $< -o $@ $(I_LINKS) $(L_LINKS)

clean:
	@$(RM) $(OP)
	@(cd ./libft/ && make clean)

fclean: clean
	@$(RM) $(NAME)
	@(cd ./libft/ && make fclean)

re: fclean all

.PHONY: clean, re,
