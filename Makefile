# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 14:26:54 by aherbin           #+#    #+#              #
#    Updated: 2024/02/20 16:43:31 by aherbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

NAME = Minitalk

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I include/

RM = rm -f

CYAN = \033[0;1;3;36m
GREEN = \033[0;1;32m
RED = \033[0;1;31m
BLUE = \033[0;34m
ECEND = \033[0m

SRC_SRV = src/server.c

SRC_CLIENT = src/client.c

CLIENT = client

SERVER = server

SRC_COMMON = src/common.c

COMMON = common.o

SRC_SRV_BONUS = src_bonus/server_bonus.c

SRC_CLIENT_BONUS = src_bonus/client_bonus.c

SRC_COMMON_BONUS = src_bonus/common_bonus.c

COMMON_BONUS = common_bonus.o

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(COMMON): $(SRC_COMMON)
	@$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled"

$(CLIENT): $(SRC_CLIENT) $(COMMON)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_CLIENT) $(COMMON) -o $(CLIENT)
	@echo "$(CYAN)$(CLIENT) $(BLUE)successfully created!$(ECEND)"

$(SERVER): $(SRC_SRV) $(COMMON)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_SRV) $(COMMON) -o $(SERVER)
	@echo "$(CYAN)$(SERVER) $(BLUE)successfully created!$(ECEND)"

bonus: all $(SERVER_BONUS) $(CLIENT_BONUS)

$(COMMON_BONUS): $(SRC_COMMON_BONUS)
	@$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled"

$(CLIENT_BONUS) : $(SRC_CLIENT_BONUS) $(COMMON_BONUS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_CLIENT_BONUS) $(COMMON_BONUS) -o $(CLIENT_BONUS)
	@echo "$(CYAN)$(CLIENT_BONUS) $(BLUE)successfully created!$(ECEND)"

$(SERVER_BONUS) : $(SRC_SRV_BONUS) $(COMMON_BONUS)
	@$(CC) $(CCFLAGS) $(INCLUDES) $(SRC_SRV_BONUS) $(COMMON_BONUS) -o $(SERVER_BONUS)
	@echo "$(CYAN)$(SERVER_BONUS) $(BLUE)successfully created!$(ECEND)"

clean:
	@$(RM)  $(COMMON) $(COMMON_BONUS)
	@echo "$(RED)common objs deleted $(ECEND)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(RED)$(NAME) $(BLUE)successfully deleted$(ECEND)"

re: fclean all

.PHONY: all bonus clean fclean re
