# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 20:40:30 by msales-a          #+#    #+#              #
#    Updated: 2021/10/20 08:48:38 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

# CONFIG

DIRECTORY_SOURCE	:= src
DIRECTORY_HEADER	:= includes
DIRECTORY_TARGET	:= target

LIBRARIES_SYSTEM	:= -lreadline
LIBRARIES_COMPILED	:= ./libs/libft/libft.a

# PREPARE

LIBRARIES_FLAGS_UTIL		= -L$(dir $(library)) -l$(patsubst lib%.a,%, $(notdir $(library)))
LIBRARIES_COMPILED_FLAGS	:= $(foreach library, $(LIBRARIES_COMPILED), $(LIBRARIES_FLAGS_UTIL))
LIBRARIES_FLAGS				:= $(LIBRARIES_COMPILED_FLAGS) $(LIBRARIES_SYSTEM)

# FILE_SOURCE	:= $(filter %.c, $(shell find $(DIRECTORY_SOURCE) -type f))
FILE_SOURCE	:= src/signals.c \
	src/builtins/cd.c \
	src/builtins/exit.c \
	src/builtins/unset.c \
	src/builtins/echo.c \
	src/builtins/export.c \
	src/builtins/pwd.c \
	src/builtins/env.c \
	src/prompt.c \
	src/tokens/token_escaper.c \
	src/tokens/tokens_validator.c \
	src/tokens/token_recognition.c \
	src/tokens/token_util.c \
	src/utils/ignore_signal.c \
	src/utils/free.c \
	src/utils/path_formater.c \
	src/utils/error_handler.c \
	src/utils/set_variable.c \
	src/utils/pipe_util.c \
	src/utils/is_directory.c \
	src/utils/paths.c \
	src/utils/str_list_to_array.c \
	src/utils/pipe_minishell.c \
	src/utils/array_size.c \
	src/utils/ft_strrstr.c \
	src/here_document/parser_core.c \
	src/here_document/here_document_parser.c \
	src/here_document/here_document.c \
	src/parser/expand_variables.c \
	src/parser/join_words.c \
	src/parser/show.c \
	src/env/path.c \
	src/env/env.c \
	src/commands/get_next_command.c \
	src/commands/command.c \
	src/commands/redirects.c \
	src/commands/operators.c \
	src/commands/program.c \
	src/commands/process_commands.c \
	src/hashmap/free.c \
	src/hashmap/index.c \
	src/hashmap/get_keys.c \
	src/hashmap/create.c \
	src/hashmap/operations.c \
	src/main.c \

OBJECTS_SOURCE	:= $(addprefix $(DIRECTORY_TARGET)/, $(FILE_SOURCE:.c=.o))

COMPILER		:= clang
COMPILER_FLAGS	:= -Wall -Wextra -Werror -g

HANDLER = solver

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
	@$(foreach library, $(LIBRARIES_COMPILED), make -C $(dir $(library)) clean)

fclean : clean
	@rm -f $(NAME)
	@$(foreach library, $(LIBRARIES_COMPILED), make -C $(dir $(library)) fclean)

re : clean all

$(NAME) : $(OBJECTS_SOURCE) $(LIBRARIES_COMPILED)
	@$(COMPILER) $(COMPILER_FLAGS) $(OBJECTS_SOURCE) $(LIBRARIES_FLAGS) -o $(NAME)

$(BONUS_NAME) : $(OBJECTS_SOURCE_BONUS) $(LIBRARIES_COMPILED)
	@$(COMPILER) $(COMPILER_FLAGS) $(OBJECTS_SOURCE_BONUS) $(LIBRARIES_FLAGS) -o $(BONUS_NAME)

$(DIRECTORY_TARGET)/%.o : %.c Makefile
	@mkdir -p $(@D)
	@$(COMPILER) -I$(DIRECTORY_HEADER) $(COMPILER_FLAGS) -c $< -o $@

$(LIBRARIES_COMPILED) :
	@$(MAKE) -C $(dir $@)
