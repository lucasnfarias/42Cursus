# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 01:23:05 by coder             #+#    #+#              #
#    Updated: 2022/03/12 12:53:51 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := the_job_of_your_nightmare

# CONFIG

DIRECTORY_TARGET	:= target

FILE_SOURCE	:= tests.cpp Account.cpp

COMPILER		:= c++
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
	@$(COMPILER) $(COMPILER_FLAGS) $(FILE_SOURCE) -o $(NAME)
