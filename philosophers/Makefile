# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 20:40:30 by msales-a          #+#    #+#              #
#    Updated: 2021/10/31 19:34:44 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

# CONFIG

DIRECTORY_SOURCE	:= src
DIRECTORY_HEADER	:= includes
DIRECTORY_TARGET	:= target

FILE_SOURCE	:= $(filter %.c, $(shell find $(DIRECTORY_SOURCE) -type f))

OBJECTS_SOURCE	:= $(addprefix $(DIRECTORY_TARGET)/, $(FILE_SOURCE:.c=.o))

COMPILER		:= clang
COMPILER_FLAGS	:= -Wall -Wextra -Werror -g -pthread

ifeq ($(SANITIZE_A),true)
        COMPILER_FLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
        COMPILER_FLAGS += -fsanitize=leak
endif

# RECIPES

.PHONY : all clean fclean make re

all : $(NAME)

clean :
	@rm -rf $(DIRECTORY_TARGET)

fclean : clean
	@rm -f $(NAME)

re : clean all

$(NAME) : $(OBJECTS_SOURCE)
	@$(COMPILER) $(COMPILER_FLAGS) $(OBJECTS_SOURCE) -o $(NAME)

$(BONUS_NAME) : $(OBJECTS_SOURCE_BONUS)
	@$(COMPILER) $(COMPILER_FLAGS) $(OBJECTS_SOURCE_BONUS) -o $(BONUS_NAME)

$(DIRECTORY_TARGET)/%.o : %.c Makefile
	@mkdir -p $(@D)
	@$(COMPILER) -I$(DIRECTORY_HEADER) $(COMPILER_FLAGS) -c $< -o $@
