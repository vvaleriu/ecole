#!bin/zsh
gcc -Wall -Wextra -Werror -g ./srcs/*.c ./srcs/tools/*.c  ./srcs/builtins/*.c  ./srcs/execute/*.c  ./srcs/init/*.c  ./srcs/lexer/*.c  ./srcs/parser/*.c -I./headers/ -I./libft/header/ -L./libft/ -lft
