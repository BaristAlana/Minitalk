# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 17:48:20 by aherbin           #+#    #+#              #
#    Updated: 2024/01/28 18:29:19 by aherbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

NAME = server client

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

SRC_SRV = Server_SRC/server.c

SRC_CLIENT = Client_SRC/client.c

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME):
	@make printf -C $(LIBFT)
	@cp libft/libft.a .
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_SRV) libft.a -o server
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_CLIENT) libft.a -o client
	@echo "$(CYAN)$(NAME) $(BLUE)successfully created!$(ECEND)"

clean:
	@make clean -C $(LIBFT)
	@echo "$(RED)OBJS $(BLUE)successfully deleted$(ECEND)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) libft.a
	@make fclean -C $(LIBFT)
	@echo "$(RED)$(NAME) & libft/libft.a $(BLUE)successfully deleted$(ECEND)"

re: fclean all

.PHONY: all bonus clean fclean re
