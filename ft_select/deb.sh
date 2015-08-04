#!/bin/sh
gcc -g3 -Wall -Wextra -Werror ./srcs/*.c ./srcs/printing/*.c ./srcs/tools/*.c ./srcs/key_handlers/*.c ./srcs/sig_handlers/*.c ./srcs/term_setup/*.c -I./headers -I./libft/header -L./libft -lft -ltermcap
