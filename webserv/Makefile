# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:16:47 by lniehues          #+#    #+#              #
#    Updated: 2022/12/22 13:50:42 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= webserv

INCLUDES	:= $(addprefix -I, $(SRCS_DIR))

HEADERS	=	main.hpp

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -std=c++98

SRCS_DIR	:=	srcs
SRCS := main.cpp

OBJ_DIR		:= objs
OBJS		:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o:	$(SRCS_DIR)/%.cpp # this might need to check headers too
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

PHONY:		all clean fclean re
