# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:55:22 by lniehues          #+#    #+#              #
#    Updated: 2021/03/13 19:55:22 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project executable filename
NAME = minishell

# Project source files and object files
SRC_DIR = ./src/
SRCS = $(shell ls $(SRC_DIR) | grep -E ".+\.c")
INCLUDE_DIR = ./include/
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# Libft builds and dirs
LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
LIBFT_INC = ./libft/includes/

# Optimization and Compiler flags and commands
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
RM = rm -rf

ifeq ($(SANITIZE_A),true)
	CC_FLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
	CC_FLAGS += -fsanitize=leak
endif

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "\n\033[0;32m=> Compiled minishell sucessfully...\n\033[0;0m"
	@echo "\n\n🔥😈\033[0;31m THOSE WHO SHALL ENTER ITS DOMAIN MUST ABANDON ALL HOPE \033[0;0m😈🔥\n\n"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -I$(LIBFT_INC) -I$(INCLUDE_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re