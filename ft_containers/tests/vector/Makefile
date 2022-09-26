# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:16:47 by lniehues          #+#    #+#              #
#    Updated: 2022/09/26 18:44:27 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT		:=	../../

CONTAINERS_DIR	:=	$(ROOT)containers/
CONTAINERS		:=	vector.hpp

ITERATORS_DIR	:=	$(ROOT)iterators/
ITERATORS		:=	random_access_iterator.hpp \
								iterators_traits.hpp \
								reverse_iterator.hpp

UTILS_DIR	:=	$(ROOT)utils/
UTILS		:=	algorithm.hpp \
						type_traits.hpp \
						pair.hpp

TEMPLATES_DIR	:= $(CONTAINERS_DIR) $(ITERATORS_DIR) $(UTILS_DIR)
TEMPLATES		:= $(CONTAINERS) $(ITERATORS) $(UTILS)

VPATH	:=	$(TEMPLATES_DIR)

INCLUDES	:= $(addprefix -I, $(TEMPLATES_DIR))

HEADERS	=	tests_main.hpp

NAME	:= ft_tests.out
STD_NAME	:= std_tests.out

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -std=c++98

STD_VERSION := -D STD_VERSION

RM		:=	rm -rf

SRCS := tests_main.cpp clear.cpp empty.cpp erase.cpp resize.cpp reserve.cpp \
				constructors.cpp

STD_OBJ_DIR		:= std_objs
FT_OBJ_DIR	:= ft_objs
STD_OBJS		:= $(addprefix $(STD_OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))
FT_OBJS		:= $(addprefix $(FT_OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

$(STD_OBJ_DIR)/%.o:	%.cpp $(HEADERS) $(TEMPLATES)
	$(CC) $(STD_VERSION) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_OBJ_DIR)/%.o:	%.cpp $(HEADERS) $(TEMPLATES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(FT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(STD_NAME):	$(STD_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(FT_OBJS): | $(FT_OBJ_DIR)

$(FT_OBJ_DIR):
	mkdir $(FT_OBJ_DIR)

$(STD_OBJS): | $(STD_OBJ_DIR)

$(STD_OBJ_DIR):
	mkdir $(STD_OBJ_DIR)

clean:
	$(RM) $(STD_OBJ_DIR) $(FT_OBJ_DIR)

fclean:		clean
	$(RM) $(NAME) $(STD_NAME)

re:			fclean all

PHONY:		all clean fclean re
