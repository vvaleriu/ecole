# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2015/05/27 14:10:17 by vvaleriu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor.out
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11
HEADERS = -I./headers -I./srcs
LIBS =
RM = rm -rf
vpath %.cpp ./srcs
vpath %.hpp includes libft/includes
OBJ = $(SRC:%.cpp=$(OP)%.o)
OP = ./.obj/
SRC = main.cpp					\
		equation.cpp			\

all: $(NAME)

deb: 
	gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

scan: 
	scanbuild gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(HEADERS) $(LIBS)
	echo Compile done

$(OP)%.o: %.cpp
	@(mkdir -p $(OP))
	@$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS) $(LIBS)

clean:
	@$(RM) $(OP)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re,
