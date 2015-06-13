#!/bin/sh
gcc -g3 -Wall -Wextra -Werror -o ../bin/a.out ./srcs/*.c srcs/execute/*.c ./srcs/lexer/*.c ./srcs/network/*.c ./srcs/tools/*.c -I./headers -I../libs/libft/headers -L../libs -lft
