# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 19:26:55 by lniehues          #+#    #+#              #
#    Updated: 2022/09/20 12:49:38 by lniehues         ###   ########.fr        #
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

run_vector_test: vector_test
		./tests/vector/ft_tests.out > ft
		./tests/vector/std_tests.out > std
		diff ft std &>/dev/null
		rm ft std

run_map_test: map_test
		./tests/map/ft_tests.out > ft
		./tests/map/std_tests.out > std
		diff ft std &>/dev/null
		rm ft std

clean:
		make clean -C $(VECTOR_TEST_DIR)
		make clean -C $(MAP_TEST_DIR)

fclean:
		make fclean -C $(VECTOR_TEST_DIR)
		make fclean -C $(MAP_TEST_DIR)

re:		fclean all

PHONY:	all clean fclean re vector_test map_test run_vector_test run_map_test
