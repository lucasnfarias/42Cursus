/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:16:33 by lniehues          #+#    #+#             */
/*   Updated: 2021/03/04 23:11:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libasm.h"
#include "libtests.h"

static void	test_ft_strlen(void)
{
	printf("\n📚📚📚 1. TESTE - ft_strlen x strlen 📚📚📚\n\n");
	strlen_test_print("");
	strlen_test_print("42");
	strlen_test_print("0123456789abcdef");
	strlen_test_print("Lorem ipsum dolor sit amet, \
	consectetur adipiscing elit, sed do eiusmod tempor incididunt ut \
	labore et dolore magna aliqua. Ut enim ad minim veniam, quis \
	nostrud exercitation ullamco laboris \
	nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in \
	reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
	pariatur. Excepteur sint occaecat cupidatat non proident, sunt in \
	culpa qui officia deserunt mollit anim id est laborum.");
	printf("\n\n>>>>>>>>>>> (☞ﾟヮﾟ)☞ DONE! 1/6 ☜(ﾟヮﾟ☜) <<<<<<<<<<<<\n\n");
}

static void	test_ft_strdup(void)
{
	char	*tmp;
	char	*tmp2;

	errno = 0;
	tmp = NULL;
	tmp2 = NULL;
	printf("\n📚📚📚 6. TESTE - ft_strdup x strdup 📚📚📚\n\n");
	strdup_test_print(tmp, tmp2, "");
	strdup_test_print(tmp, tmp2,
		"By being lazy you are delaying Universe's Thermical Death. Good job!");
	strdup_test_print(tmp, tmp2, "Lorem ipsum dolor sit amet, \
	consectetur adipiscing elit, sed do eiusmod tempor incididunt ut \
	labore et dolore magna aliqua. Ut enim ad minim veniam, quis \
	nostrud exercitation ullamco laboris \
	nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in \
	reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
	pariatur. Excepteur sint occaecat cupidatat non proident, sunt in \
	culpa qui officia deserunt mollit anim id est laborum.");
	printf("\n\n>>>>>>>>>>> (☞ﾟヮﾟ)☞ DONE! 6/6 ☜(ﾟヮﾟ☜) <<<<<<<<<<<<\n\n");
}

int			main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}
