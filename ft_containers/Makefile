# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:26:55 by lniehues          #+#    #+#              #
#    Updated: 2022/09/13 16:41:40 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		:=	rm -rf

TESTS_DIR	:=	./tests/

VECTOR_TEST_DIR	:=	$(TESTS_DIR)vector
MAP_TEST_DIR	:=	$(TESTS_DIR)map

all:	vector_test map_test

vector_test:
		make -C $(VECTOR_TEST_DIR)
		make -C $(VECTOR_TEST_DIR) std_tests.out

map_test:
		make -C $(MAP_TEST_DIR)
		make -C $(MAP_TEST_DIR) std_tests.out

clean:
		make clean -C $(VECTOR_TEST_DIR)
		make clean -C $(MAP_TEST_DIR)

fclean:
		make fclean -C $(VECTOR_TEST_DIR)
		make fclean -C $(MAP_TEST_DIR)

re:		fclean all

PHONY:	all clean fclean re vector_test map_test
