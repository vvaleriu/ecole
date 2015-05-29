# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 14:33:36 by vvaleriu          #+#    #+#              #
#    Updated: 2015/02/02 11:36:54 by vvaleriu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBDIRS = client server
LIBDIR = ./libs
BIN_PATH = ./bin
LIBS = $(LIBDIR)/libft
RM = rm -rf

all: $(SUBDIRS)

scan: 
	scanbuild gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

$(SUBDIRS): $(BIN_PATH) $(LIBS) $(SUBDIRS)
	@$(MAKE) -C $@
	$@ compiled 

$(BIN_PATH):
	@(mkdir -p $@)

$(LIBS):
	@$(MAKE) -C $@

clean:
	$(MAKE) -C client clean
	$(MAKE) -C server clean
	$(MAKE) -C libs/libft clean
fclean: clean
	@$(RM) $(BIN_PATH):
	@($(MAKE) -C libs/libft fclean)

re: fclean all

.PHONY: clean, re, $(SUBDIRS), $(LIBS)
