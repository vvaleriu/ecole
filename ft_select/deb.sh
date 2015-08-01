#!/bin/sh
gcc -g3 -Wall -Wextra -Werror ./srcs/*.c ./srcs/tools/*.c ./srcs/key_handlers/*.c ./srcs/sig_handlers/*.c ./srcs/init/*.c ./srcs/term_setup/*.c -I./headers -I./libft/header -L./libft -lft -ltermcap
