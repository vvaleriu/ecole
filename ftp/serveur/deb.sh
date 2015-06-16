#!/bin/sh
gcc -g3 -Wall -Wextra -Werror -o ../bin/s.out ./srcs/*.c ../common/srcs/*.c srcs/execute/*.c ./srcs/lexer/*.c ./srcs/network/*.c ./srcs/tools/*.c -I./headers -I../libs/libft/headers -I../common/headers -L../libs -lft
