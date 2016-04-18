DEBUG	= debug
NAME	= eval_expr
CC		= clang
LIBFT	= ../libft/libft.a
IFLAG	= -I ./ -I ../libft/header
LFLAG	= -L ../libft/ -lft
WFLAG	= -Wall -Werror -Wextra
RM		= rm -Rf
H		= main.h 					\
			struct.h

SRC		= main.c 					\
			ft_operation.c			\
			ft_atof.c				\
			ft_init_env.c 			\
			ft_init_matrice_char.c 	\
			ft_matrice_char_len.c 	\
			ft_is_operator.c 		\
			ft_is_digit.c 			\
			ft_is_number.c 			\
			ft_read_token.c 		\
			ft_postfix.c 			\
			ft_shunting_yard.c 		\
			ft_check_error.c 		\
			ft_get_precedence.c 	\
			ft_stack.c 				\
			ft_queue.c

OBJ		= $(SRC:.c=.o)

$(NAME):  $(OBJ) $(H)
	@$(CC) $(WFLAG) $(LFLAG) $(IFLAG) $(OBJ) -o $@
	@echo "eval_expr ready"

%.o:%.c
	@$(CC) $(WFLAG) $(IFLAG) -o $@ -c $<

$(DEBUG): $(H)
	@$(CC) $(WFLAG) -g $(LFLAG) $(IFLAG) $(SRC) -o $@

all: $(NAME)

debug: $(DEBUG)

clean:
	@$(RM) $(OBJ)
	@echo "eval_expr: objects deleted"

dclean:
	@$(RM) $(DEBUG).dSYM $(DEBUG)

fclean: clean
	@$(RM) $(NAME)
	@echo "eval_expr deleted"

re: fclean all

.PHONY: all, clean, fclean, re
