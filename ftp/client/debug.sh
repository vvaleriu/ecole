#!/bin/sh
gcc -g3 -Wall -Wextra -Werror -o ../bin/c/c.out ./srcs/*.c ./srcs/commands/*.c ./srcs/network/*.c ../common/srcs/tools/*.c \
./srcs/tools/*.c ../common/srcs/*.c ../common/srcs/network/*.c ../common/srcs/lexer/*.c  ./srcs/send/*.c ./srcs/receive/*.c \
-I./headers -I../libs/libft/header -I../common/headers -L../libs/libft -lft
