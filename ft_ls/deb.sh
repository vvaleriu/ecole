#!/bin/sh
gcc -g3 -Wall -Wextra -Werror -I./headers -I./libft/header ./srcs/*.c ./srcs/files_prop/*.c ./srcs/display/*.c ./srcs/tools/*.c	./srcs/lists/*.c -L./libft -lft 
