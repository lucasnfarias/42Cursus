# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 21:09:49 by lniehues          #+#    #+#              #
#    Updated: 2021/08/18 21:37:14 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

INCLUDES	= -I include -I $(LIBFT_DIR)

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft
LFT_FLAGS	= -L $(LIBFT_DIR) -lft

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= main

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
			@echo "Compiled "$<" successfully!"

all:		$(NAME)

$(LIBFT):
			@make --no-print-directory -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS) $(LFT_FLAGS)
			@echo "\n\033[0;32mCreated push_swap executable file successfully!\n\033[0;0m"

clean:
			@make clean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)
			@echo "\n\033[1;33mWow... that is some cleanup!\n\033[0;0m"

fclean:		clean
			@make fclean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
