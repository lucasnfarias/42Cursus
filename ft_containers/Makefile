# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:26:55 by lniehues          #+#    #+#              #
#    Updated: 2022/08/09 22:07:28 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		:=	rm -rf

TESTS_DIR	:=	./tests/

VECTOR_TEST_DIR	:=	$(TESTS_DIR)vector

all:	vector_test

vector_test:
		make -C $(VECTOR_TEST_DIR)
		make -C $(VECTOR_TEST_DIR) std_tests.out

clean:
		make clean -C $(VECTOR_TEST_DIR)

fclean:
		make fclean -C $(VECTOR_TEST_DIR)

re:		fclean all

PHONY:	all clean fclean re vector_test map_test
