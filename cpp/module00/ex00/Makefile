# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 01:23:05 by coder             #+#    #+#              #
#    Updated: 2022/01/27 01:28:18 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

# CONFIG

DIRECTORY_TARGET	:= target

FILE_SOURCE	:= megaphone.cpp

COMPILER		:= g++
COMPILER_FLAGS	:= -Wall -Wextra -Werror

ifeq ($(SANITIZE_A),true)
        COMPILER_FLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
        COMPILER_FLAGS += -fsanitize=leak
endif

# RECIPES

.PHONY : all clean fclean make re

all : $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(FILE_SOURCE)
	@$(COMPILER) $(COMPILER_FLAGS) $(FILE_SOURCE) -o $(NAME)
