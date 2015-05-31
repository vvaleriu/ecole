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

BIN = client serveur
CLIENT = client
SERVEUR = serveur
LIBDIR = ./libs
BIN_PATH = ./bin
LIBS = $(LIBDIR)/libft
RM = rm -rf

all: $(BIN)

scan: 
	scanbuild gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

$(BIN): $(BIN_PATH) $(LIBS) $(CLIENT) $(SERVEUR)
	@$(MAKE) -C $@	

$(BIN_PATH):
	@(mkdir -p $@)

$(LIBS):
	@$(MAKE) -C $@

clean:
	$(MAKE) -C $(CLIENT) clean
	$(MAKE) -C $(SERVEUR) clean
	$(MAKE) -C libs/libft clean

fclean: clean
	@$(RM) $(BIN_PATH):
	@($(MAKE) -C libs/libft fclean)

re: fclean all

.PHONY: clean, re, $(BIN), $(LIBS), $(CLIENT), $(SERVEUR)
