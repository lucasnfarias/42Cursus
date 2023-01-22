# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:16:47 by lniehues          #+#    #+#              #
#    Updated: 2023/01/22 16:23:15 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= webserv


HEADERS	=	main.hpp

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -std=c++98

SRCS_DIR	:=	srcs
INCL_DIR := includes
OBJ_DIR		:= objs

SRCS := main.cpp

# INCLUDES := $(INCL_DIR)/WebServer.hpp

OBJS		:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o:	$(SRCS_DIR)/%.cpp $(INCLUDES)# this might need to check headers too
	$(CC) $(CFLAGS) -I ./$(INCL_DIR) -c $< -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

PHONY:		all clean fclean re
