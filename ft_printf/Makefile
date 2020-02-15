# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 18:19:38 by lniehues          #+#    #+#              #
#    Updated: 2020/02/13 12:40:21 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
LIBFT =	libft
LIBFT_LIB =	libft.a

SRCS =	./ft_printf.c \
		./ft_printf_manager.c \
		./ft_printf_putchar.c \
		./ft_printf_putstr.c \
		./ft_printf_format_handle.c \
		./ft_printf_flags_init.c \
		./ft_printf_format_char.c \
		./ft_printf_format_decimal.c \
		./ft_printf_format_str.c \
		./ft_printf_format_percentage.c \
		./ft_printf_format_pointer.c \
		./ft_printf_format_int_hex.c \
		./ft_printf_format_uint.c \
		./ft_printf_parse_flags.c \
		./ft_printf_padders.c \
		./ft_itoa_base.c \
		./ft_empty_str.c \
		./ft_printf_putdecimal.c \

OBJS = 	$(SRCS:.c=.o)

RM = rm -f
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror
INCS = .
COMPILER = gcc

.c.o:
			${COMPILER} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME):	${OBJS}
			make all -C $(LIBFT)/
			cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
			${LIBC} $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_B)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME) $(bonus)	
			make fclean -C $(LIBFT)

re:			fclean all

bonus:		all

.PHONY:		teste all clean fclean re bonus .c.o
