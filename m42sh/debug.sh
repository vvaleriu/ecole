#!bin/zsh
gcc -Wall -Wextra -Werror -g ./srcs/*.c ./srcs/tools/*.c  ./srcs/builtins/*.c  ./srcs/execute/*.c  ./srcs/init/*.c  ./srcs/lexer/*.c  ./srcs/parser/*.c ./srcs/completion/*.c ./srcs/termcaps/key_handlers/*.c ./srcs/termcaps/printing/*.c ./srcs/termcaps/setup/*.c ./srcs/termcaps/tools/*.c ./srcs/signals/*.c ./srcs/inputs/*.c -I./headers/ -I./libft/header/ -L./libft/ -lft -ltermcap
