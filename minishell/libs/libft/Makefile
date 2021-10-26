# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 17:28:56 by msales-a          #+#    #+#              #
#    Updated: 2021/10/14 07:38:29 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

SOURCE_DIRECTORY	:= srcs
HEADER_DIRECTORY	:= srcs/includes
TARGET_DIRECTORY	:= target

SOURCE_FILES	:= $(filter %.c, $(shell find $(SOURCE_DIRECTORY) -type f))
OBJECT_FILES	:= $(subst $(SOURCE_DIRECTORY)/,/, $(SOURCE_FILES:.c=.o))
OBJECT_WITH_DIR	:= $(addprefix $(TARGET_DIRECTORY), $(OBJECT_FILES))

COMPILER		:= gcc
COMPILER_FLAGS	:= -Wall -Wextra -Werror -g

ARCHIVE			:= ar
ARCHIVE_FLAGS	:= -rcs

.PHONY : all clean fclean make re bonus
.SILENT : all clean fclean make re bonus

all : $(NAME)

$(NAME) : $(OBJECT_WITH_DIR)
	@$(ARCHIVE) $(ARCHIVE_FLAGS) $(NAME) $(OBJECT_WITH_DIR)

$(TARGET_DIRECTORY)/%.o : $(SOURCE_DIRECTORY)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) -I$(HEADER_DIRECTORY) $(COMPILER_FLAGS) -c $< -o $@

clean :
	@rm -rf $(TARGET_DIRECTORY)

fclean :
	@rm -f $(NAME)

re : all clean

bonus : all
