#!/bin/sh
gcc -g3 -Wall -Wextra -Werror -o ../bin/c.out ./srcs/*.c ./srcs/network/*.c ./srcs/tools/*.c ../common/srcs/*.c ./srcs/send/*.c ./srcs/receive/*.c -I./headers -I../libs/libft/headers -I../common/headers -L../libs -lft
