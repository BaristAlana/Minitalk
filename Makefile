# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 17:48:20 by aherbin           #+#    #+#              #
#    Updated: 2024/01/29 18:05:51 by aherbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

NAME = Minitalk

CC = cc

CCFLAGS = -Wall -Wextra -Werror

INCLUDES = -I include/

RM = rm -f

CYAN = \033[0;1;3;36m
GREEN = \033[0;1;32m
RED = \033[0;1;31m
BLUE = \033[0;34m
ECEND = \033[0m

LIBFT = libft

LIBFT_A = libft.a

SRC_SRV = Server_SRC/server.c

SRC_CLIENT = Client_SRC/client.c

CLIENT = client

SERVER = server

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME) $(SUBDIRS)

SUBDIRS = libft/src

$(SUBDIRS):
	$(MAKE) -C $@

$(NAME): $(CLIENT) $(SERVER)

$(LIBFT_A):
	@make printf -C $(LIBFT)
	@cp libft/libft.a .

$(CLIENT): $(LIBFT_A) $(SRC_CLIENT)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBFT_A) -o client
	@echo "$(CYAN)$(CLIENT) $(BLUE)successfully created!$(ECEND)"

$(SERVER): $(LIBFT_A) $(SRC_SRV)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_SRV) $(LIBFT_A) -o server
	@echo "$(CYAN)$(SERVER) $(BLUE)successfully created!$(ECEND)"

clean:
	@make clean -C $(LIBFT)
	@echo "$(RED)OBJS $(BLUE)successfully deleted$(ECEND)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(RM) libft.a
	@make fclean -C $(LIBFT)
	@echo "$(RED)$(NAME) & libft/libft.a $(BLUE)successfully deleted$(ECEND)"

re: fclean all

.PHONY: all bonus clean fclean re
