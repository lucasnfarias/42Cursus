# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 01:23:05 by coder             #+#    #+#              #
#    Updated: 2022/01/31 20:53:25 by lniehues         ###   ########.fr        #
#                                                                              #
# *****************c********************************************************** #

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

ifeq ($(STD98),true)
        COMPILER_FLAGS += -std=c++98
endif

# RECIPES

.PHONY : all clean fclean make re

all : $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(FILE_SOURCE)
	$(COMPILER) $(COMPILER_FLAGS) $(FILE_SOURCE) -o $(NAME)
