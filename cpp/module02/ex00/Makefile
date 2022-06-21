# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 01:23:05 by coder             #+#    #+#              #
#    Updated: 2022/04/05 19:40:23 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fixedPoint

# CONFIG

FILE_SOURCE	:= main.cpp Fixed.class.cpp

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
