# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 14:15:08 by aherbin           #+#    #+#              #
#    Updated: 2024/01/28 18:31:11 by aherbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

NAME = libft.a

CC = cc

CCFLAGS = -Wall -Wextra -Werror

ARNAME = ar crs $(NAME)

INCLUDES = -I include

RM = rm -f

MKDIR_P = mkdir -p

CYAN = \033[0;1;36m
GREEN = \033[0;1;32m
RED = \033[0;1;31m
BLUE = \033[0;34m
ECEND = \033[0m

#          LIBFT          #

SRC_DIR = src/

OBJS_DIR = objs/

LIBFT_FILES = isalpha isdigit isalnum \
		isascii isprint atoi \
		bzero calloc itoa \
		memchr memcmp memcpy \
		memmove memset \
		putchar_fd putendl_fd putnbr_fd \
		putstr_fd split strchr \
		strdup striteri strjoin \
		strlcat strlcpy strlen \
		strmapi strncmp strnstr \
		strrchr strtrim substr \
		tolower toupper\
		lstnew lstadd_front lstsize \
		lstlast lstadd_back lstdelone \
		lstclear lstiter lstmap \

SRC = $(addprefix $(SRC_DIR)ft_, $(addsuffix .c, $(LIBFT_FILES)))

OBJS := $(addprefix $(OBJS_DIR)ft_, $(addsuffix .o, $(LIBFT_FILES)))

#         PRINTF          #

PRINTF_SRC_DIR = $(SRC_DIR)printf

PRINTF_OBJS_DIR = $(OBJS_DIR)printf/

PRINTF_FILES = printf printf_c printf_s \
		printf_n printf_phex printf_u

PRINTF_SRC = $(addprefix $(PRINTF_SRC_DIR)ft_, $(addsuffix .c, $(PRINTF_FILES)))

PRINTF_OBJS := $(addprefix $(PRINTF_OBJS_DIR)ft_, $(addsuffix .o, $(PRINTF_FILES)))

#           GNL           #

GNL_SRC_DIR = $(SRC_DIR)gnl

GNL_OBJS_DIR = $(OBJS_DIR)gnl/

GNL_FILES = get_next_line

GNL_SRC = $(addprefix $(GNL_SRC_DIR), $(addsuffix .c, $(GNL_FILES)))

GNL_OBJS := $(addprefix $(GNL_OBJS_DIR), $(addsuffix .o, $(GNL_FILES)))

# **************************************************************************** #
#                                 LIBFT RULES                                  #
# **************************************************************************** #

all: libft_std printf gnl

libft_std: $(NAME)

$(NAME): directories $(OBJS)
	@$(ARNAME) $(OBJS)
	@echo "$(CYAN)$(NAME) $(BLUE)created"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(INCLUDES) $(CCFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled$(ECEND)"

$(OBJS_DIR):
	@$(MKDIR_P) $(OBJS_DIR)

# **************************************************************************** #
#                                PRINTF RULES                                  #
# **************************************************************************** #

printf: $(NAME) $(PRINTF_OBJS)
	@$(ARNAME) $(PRINTF_OBJS)
	@echo "$(CYAN) Printf $(BLUE) added to $(CYAN) $(NAME)$(ECEND)"

$(PRINTF_OBJS_DIR): $(OBJS_DIR)
	@$(MKDIR_P) $(PRINTF_OBJS_DIR)

$(PRINTF_OBJS_DIR)%.o: $(PRINTF_SRC_DIR)%.c
	@$(CC) $(INCLUDES) $(CCFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled$(ECEND)"

# **************************************************************************** #
#                                  GNL RULES                                   #
# **************************************************************************** #

gnl: $(NAME) $(GNL_OBJS)
	@$(ARNAME) $(GNL_OBJS)
	@echo "$(CYAN) Get_Next_Line $(BLUE) added to $(CYAN) $(NAME)$(ECEND)"

$(GNL_OBJS_DIR): $(OBJS_DIR)
	@$(MKDIR_P) $(GNL_OBJS_DIR)

$(GNL_OBJS_DIR)%.o: $(GNL_SRC_DIR)%.c
	@$(CC) $(INCLUDES) $(CCFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@ $(BLUE)successfully compiled$(ECEND)"

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

directories: $(OBJS_DIR) $(GNL_OBJS_DIR) $(PRINTF_OBJS_DIR)

clean:
	@$(RM) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)OBJS $(BLUE)successfully deleted$(ECEND)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) $(BLUE)successfully deleted$(ECEND)"

re: fclean all

.PHONY: all printf gnl libft_std directories clean fclean re
