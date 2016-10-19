#!/bin/sh
##  gcc -g3 ./srcs/debug/* ./srcs/main.c ./srcs/parser/* ./srcs/tools/* ./srcs/path/* ./srcs/algo/* ./srcs/print/* -I./headers -I./libft/header -L./libft -lft
gcc -g3 ./srcs/print/print_mouv.c ./srcs/debug/print.c ./srcs/main.c ./srcs/parser/assert.c ./srcs/parser/parse_link.c ./srcs/parser/parser.c ./srcs/parser/parse_room.c ./srcs/parser/read_entry.c  ./srcs/tools/clean.c ./srcs/tools/init.c ./srcs/tools/tools.c  ./srcs/path/deep_search.c ./srcs/path/width_search.c  ./srcs/algo/algo.c -I./headers -I./libft/header -L./libft -lft