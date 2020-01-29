# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 12:01:49 by lniehues          #+#    #+#              #
#    Updated: 2020/01/27 16:48:52 by lniehues         ###   ########.fr        #
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
			ft_substr.c ft_tolower.c ft_toupper.c 

BONUS	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS	=	$(SOURCES:.c=.o)
OBJS_B	=	$(BONUS:.c=.o)
RM		=	rm -f
LIBC	=	ar -rcs
INCS	=	./
CC		=	gcc

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME):	${OBJS}
			@${LIBC} $(NAME) $(OBJS)
			@ranlib $(NAME)

all: 		$(NAME)

bonus: 		$(NAME) $(OBJS_B)
			@${LIBC} $(NAME) $(OBJS_B)
			
clean:
			@$(RM) -f $(OBJS) $(OBJS_B)

fclean: 	clean
			@$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus .c.o
