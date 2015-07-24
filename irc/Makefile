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
BIN_PATH = ./bin
vpath %.a ./libs/ ./libs/libft/
LIBS = ./libs/libft
RM = rm -rf

all: $(BIN)

scan: 
	scanbuild gcc -g3 -I./libft/includes main.c libft/srcs/*.c libft/srcs/printf/*.c libft/srcs/printf/conversions/*.c libft/srcs/printf/flags/*.c

$(BIN): libft.a $(BIN_PATH) $(CLIENT) $(SERVEUR)
	@$(MAKE) -C $@

$(BIN_PATH):
	@(mkdir -p $@)
	@(mkdir -p $@/c)
	@(mkdir -p $@/s)

libft.a:
	@$(MAKE) -C $(LIBS)

clean:
	$(MAKE) -C $(CLIENT) clean
	$(MAKE) -C $(SERVEUR) clean
	$(MAKE) -C $(LIBS) clean

fclean: clean
	@$(RM) $(BIN_PATH):
	@($(MAKE) -C $(LIBS) fclean)

re: fclean all

.PHONY: clean, re, $(CLIENT), $(SERVEUR)
