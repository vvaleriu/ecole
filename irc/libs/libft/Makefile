# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 15:19:26 by vvaleriu          #+#    #+#              #
#    Updated: 2015/02/10 16:20:44 by vvaleriu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -c -Wall -Wextra -Werror
FOLDER = ..
ILINKS = -I./headers
VPATH = srcs headers
vpath %.c ./srcs ./srcs/printf ./srcs/printf/conversions ./srcs/printf/flags
vpath %.h ./headers
vpath %.o ./obj
RM = rm -rf
OBJ = $(SRC:%.c=$(OP)%.o)
OP = ./obj/
SRC = ft_putchar.c			\
		ft_putstr.c			\
		ft_bzero.c			\
		ft_putnbr.c			\
		ft_putnbr_unsign.c	\
		ft_putendl.c		\
		ft_strclr.c			\
		ft_strlen.c			\
		ft_strcpy.c			\
		ft_strncpy.c		\
		ft_strdup.c			\
		ft_strndup.c		\
		ft_strcat.c			\
		ft_strncat.c		\
		ft_strlcat.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strcmp.c			\
		ft_strncmp.c		\
		ft_atoi.c			\
		ft_ftoa.c			\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_memcmp.c			\
		ft_memset.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memdup.c			\
		ft_strstr.c			\
		ft_strnstr.c		\
		ft_memchr.c			\
		ft_memalloc.c		\
		ft_memdel.c			\
		ft_strnew.c			\
		ft_strdel.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strequ.c			\
		ft_strnequ.c		\
		ft_strsub.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_strsplit.c		\
		ft_itoa.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_strrev.c			\
		ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstdel.c			\
		ft_lstadd.c			\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_elemdup.c		\
		ft_lstlen.c			\
		ft_lstadd_last.c	\
		ft_itoa_long.c		\
		ft_itoa_unsign_long.c\
		ft_itoh.c			\
		ft_itoh_cap.c		\
		ft_itoh_long.c		\
		ft_itoh_long_cap.c	\
		ft_itoo.c			\
		ft_itoa_unsign.c	\
		ft_isspace.c		\
		ft_pitrad.c 		\
		ft_atod.c			\
		ft_otoa.c			\
		ft_otoa_char.c		\
		ft_otoa_short.c		\
		ft_otoa_long.c		\
		ft_printf.c			\
		pf_init_array.c		\
		pf_print_d.c		\
		pf_print_d_long.c	\
		pf_print_d_h.c		\
		pf_print_d_hh.c		\
		pf_print_d_j.c		\
		pf_print_c.c		\
		pf_print_c_cap.c	\
		pf_print_s.c		\
		pf_print_s_cap.c	\
		pf_print_f.c		\
		pf_print_o.c		\
		pf_print_o_h.c		\
		pf_print_o_hh.c		\
		pf_print_o_long.c	\
		pf_print_x.c		\
		pf_print_x_h.c		\
		pf_print_x_hh.c		\
		pf_print_x_long.c	\
		pf_print_x_cap.c	\
		pf_print_x_cap_h.c	\
		pf_print_x_cap_hh.c	\
		pf_print_x_cap_long.c\
		pf_print_p.c		\
		pf_print_u.c		\
		pf_print_u_h.c		\
		pf_print_u_hh.c		\
		pf_print_u_long.c	\
		pf_print_purcentage.c\
		pf_repeat_char.c	\
		pf_set_accuracy.c	\
		pf_set_conv_qual.c	\
		pf_set_flags.c		\
		pf_set_width.c 		\
		pf_print_spaces.c	\
		ft_putwchar.c		\
		ft_putwstr.c		\
		ft_wstrdup.c		\
		ft_wstrndup.c		\
		ft_wstrlen.c		\
		ft_wstrdel.c		\
		ft_itoa_short.c		\
		ft_itoa_char.c		\
		ft_itoa_unsign_short.c\
		pf_check_suf.c		\
		pf_check_dcxop.c	\
		get_next_line.c		\
		is_text.c			\
		is_space.c			\
		is_operator.c		\
		ft_strarray_del.c	\
		ft_putstr_array.c	\


$(NAME): libft.h $(OBJ)
	@ar rc $(FOLDER)/$@ $(OBJ)
	@ranlib $(FOLDER)/$(NAME)
	@echo "libft.a compiled"

$(OP)%.o: %.c
	@mkdir -p $(OP)
	@$(CC) -c $(FLAGS) $< $(ILINKS) -o $@

all: $(NAME)

clean:
	@$(RM) $(OP)
	@echo "libft.a objects deleted"

fclean: clean
	@$(RM) $(FOLDER)/$(NAME)
	@echo "libft.a deleted"

re: fclean all

.PHONY: clean, fclean, re
