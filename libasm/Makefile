# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 15:07:00 by lniehues          #+#    #+#              #
#    Updated: 2021/03/04 22:42:51 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC_DIR = src/

FUNCTIONS =	ft_strlen.s	\
						ft_strcpy.s	\
						ft_strcmp.s	\
						ft_write.s	\
						ft_read.s	\
						ft_strdup.s	\

SRCS = $(addprefix $(SRC_DIR), $(FUNCTIONS))

OBJS = ${SRCS:.s=.o}

INCLUDE = ./include

ASM = nasm

ASM_FLAGS = -f elf64

CC = clang
CC_FLAGS	=	-Wall					\
						-Wextra				\
 						-Werror				\
 						-g						\
						-I${INCLUDE}	\
 						-L.						\
 						-lasm					\

TEST_DIR	=	./tests
TEST		=	${TEST_DIR}/tests.c \
					${TEST_DIR}/tests2.c	\
					${TEST_DIR}/main.c	\

BIN			=	${TEST_DIR}/main_tests
WRITE_FILES = ./tests/write.txt ./tests/ft_write.txt

RM = rm -f

ifeq ($(SANITIZE_A),true)
	CC_FLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
	CC_FLAGS += -fsanitize=leak
endif

ifeq ($(ASM_DEBUG),true)
	ASM_FLAGS += -g
endif

all: ${NAME}

%.o:%.s
	$(ASM) $(ASM_FLAGS) $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

test: $(TEST) $(NAME)
	$(CC) ${TEST} $(CC_FLAGS) -o $(BIN)
	@echo "\n🔧🔧🔧 BORA TESTAR ESSA DESGRAÇA 🔧🔧🔧\n"
	$(BIN)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BIN}
	${RM} ${WRITE_FILES}

re: fclean all

.PHONY: all clean fclean re
