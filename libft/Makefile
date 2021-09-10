# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 12:01:49 by lniehues          #+#    #+#              #
#    Updated: 2021/09/09 21:21:01 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FLAGS	=	-Wall -Wextra -Werror

SOURCES	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c ft_atoll.c

ADD_SOURCES = get_next_line.c

BONUS	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS	=	$(SOURCES:.c=.o)
ADD_OBJS	=	$(ADD_SOURCES:.c=.o)
OBJS_B	=	$(BONUS:.c=.o)
RM		=	rm -f
LIBC	=	ar -rcs
INCS	=	./
CC		=	gcc

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME):	${OBJS} ${ADD_OBJS}
			@${LIBC} $(NAME) $(OBJS) $(ADD_OBJS)
			@ranlib $(NAME)
			@echo "\n\033[0;32mCompiled libft sucessfully...\n\033[0;0m"

all: 		$(NAME)

bonus: 		$(NAME) $(OBJS_B)
			@${LIBC} $(NAME) $(OBJS_B)
			
clean:
			@$(RM) -f $(OBJS) $(OBJS_B) $(ADD_OBJS)

fclean: 	clean
			@$(RM) $(NAME)
			@echo "\n\033[1;33mWow... that is some cleanup!\n\033[0;0m"

re: 		fclean all

.PHONY:		all clean fclean re bonus .c.o
