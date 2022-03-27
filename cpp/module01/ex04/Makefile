# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 01:23:05 by coder             #+#    #+#              #
#    Updated: 2022/03/26 19:42:04 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fsdebut

# CONFIG

FILE_SOURCE	:= main.cpp FileSed.cpp

COMPILER		:= c++
COMPILER_FLAGS	:= -Wall -Wextra -Werror -std=c++98

ifeq ($(SANITIZE_A),true)
        COMPILER_FLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
        COMPILER_FLAGS += -fsanitize=leak
endif

ifeq ($(DEBUG), true)
        COMPILER_FLAGS += -g
endif

# RECIPES

.PHONY : all clean fclean make re

all : $(NAME)

fclean :
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(FILE_SOURCE)
	$(COMPILER) $(COMPILER_FLAGS) $(FILE_SOURCE) -o $(NAME)
