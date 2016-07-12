#!/bin/sh
 gcc -g3 ./srcs/entry_manager.c ./srcs/get_line_info.c ./srcs/main.c ./srcs/map_tools.c ./srcs/tools.c  -I./headers -I./libft/header -L./libft -lft