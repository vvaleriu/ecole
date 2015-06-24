#!/bin/sh
gcc -g3 -Wall -Wextra -Werror -O0 -o ../bin/s/s.out ./srcs/*.c ./srcs/commands/*.c ../common/srcs/*.c ../common/srcs/network/*.c ../common/srcs/tools/*.c ../common/srcs/lexer/*.c srcs/execute/*.c ./srcs/network/*.c ./srcs/tools/*.c ./srcs/send/*.c ./srcs/receive/*.c -I./headers -I../libs/libft/headers -I../common/headers -L../libs -lft
