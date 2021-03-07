/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:42:00 by lniehues          #+#    #+#             */
/*   Updated: 2021/03/05 10:56:12 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libasm.h"
#include "libtests.h"

void	strdup_test_print(char *tmp, char *tmp2, char *src)
{
	tmp = ft_strdup(src);
	printf("1. FT_STRDUP:\n=> DEST: `%s`\n\n=> SRC: (`%s`)\n\n", tmp, src);
	printf("errno: %d - %s\n\n", errno, strerror(errno));
	tmp2 = strdup(src);
	printf("2. STRDUP:\n=> DEST: `%s`\n\n=> SRC: (`%s`)\n\n", tmp2, src);
	printf("errno: %d - %s\n", errno, strerror(errno));
	printf("\n####################\n\n");
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;
}

void	test_ft_strcpy(void)
{
	char	buffer[1024];
	char	buffer2[1024];

	memset(buffer, 0, 1024);
	memset(buffer2, 0, 10);
	printf("\n📚📚📚 2. TESTE - ft_strcpy x strcpy 📚📚📚\n\n");
	strcpy_test_print(buffer, buffer2, "sonder");
	strcpy_test_print(buffer, buffer2, "");
	strcpy_test_print(buffer, buffer2, "Lorem ipsum dolor sit amet, \
	consectetur adipiscing elit, sed do eiusmod tempor incididunt ut \
	labore et dolore magna aliqua. Ut enim ad minim veniam, quis \
	nostrud exercitation ullamco laboris \
	nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in \
	reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
	pariatur. Excepteur sint occaecat cupidatat non proident, sunt in \
	culpa qui officia deserunt mollit anim id est laborum.");
	printf("\n\n>>>>>>>>>>> (☞ﾟヮﾟ)☞ DONE! 2/6 ☜(ﾟヮﾟ☜) <<<<<<<<<<<<\n\n");
}

void	test_ft_strcmp(void)
{
	printf("\n📚📚📚 3. TESTE - ft_strcmp x strcmp 📚📚📚\n\n");
	strcmp_test_print("", "");
	strcmp_test_print("", "testinho");
	strcmp_test_print("testinho", "");
	strcmp_test_print("testinhoCapiroto", "testinho");
	strcmp_test_print("Lorem ipsum dolor sit amet, \
	consectetur adipiscing elit, sed do eiusmod tempor incididunt ut \
	labore et dolore magna aliqua. Ut enim ad minim veniam, quis \
	nostrud exercitation ullamco laboris \
	nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in \
	reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
	pariatur. Excepteur sint occaecat cupidatat non proident, sunt in \
	culpa qui officia deserunt mollit anim id est laborum.", "Lorem \
	ipsum dolor sit amet, \
	consectetur adipiscing elit, sed do eiusmod tempor incididunt ut \
	labore et dolore magna aliqua. Ut enim ad minim veniam, quis \
	nostrud exercitation ullamco laboris \
	nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in \
	reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
	pariatur. Excepteur sint occaecat cupidatat non proident, sunt in \
	culpa qui officia deserunt mollit anim id est laborum.");
	printf("\n\n>>>>>>>>>>> (☞ﾟヮﾟ)☞ DONE! 3/6 ☜(ﾟヮﾟ☜) <<<<<<<<<<<<\n\n");
}

void	test_ft_write(void)
{
	int fd;
	int ft_fd;

	errno = 0;
	fd = open("./tests/write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_fd = open("./tests/ft_write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	printf("\n📚📚📚 4. TESTE - ft_write x write 📚📚📚\n\n");
	write_test_print(1, 1, "Testinho topzera", 16);
	write_test_print(1, 1, "totototo", 4);
	write_test_print(ft_fd, fd, "Testinho 42 maroto", 18);
	close(ft_fd);
	close(fd);
	write_test_print(-42, -42, "Testinho 42 maroto pra dar errado", 24);
	printf("\n\n>>>>>>>>>>> (☞ﾟヮﾟ)☞ DONE! 4/6 ☜(ﾟヮﾟ☜) <<<<<<<<<<<<\n\n");
}

void	test_ft_read(void)
{
	int			fds[2];
	char		buffer[1024];
	char		buffer2[1024];

	errno = 0;
	memset(buffer, 0, 1024);
	memset(buffer2, 0, 1024);
	printf("\n📚📚📚 5. TESTE - ft_read x read 📚📚📚\n\n");
	fds[0] = STDIN_FILENO;
	fds[1] = STDIN_FILENO;
	read_test_print(fds, buffer, buffer2, 100);
	fds[0] = open("src/ft_read.s", O_RDONLY);
	fds[1] = open("src/ft_read.s", O_RDONLY);
	read_test_print(fds, buffer, buffer2, 12);
	read_test_print(fds, buffer, buffer2, 42);
	read_test_print(fds, buffer, buffer2, 100);
	close(fds[0]);
	close(fds[1]);
	fds[0] = -42;
	fds[1] = -42;
	read_test_print(fds, buffer, buffer2, 100);
	printf("\n\n>>>>>>>>>>> (☞ﾟヮﾟ)☞ DONE! 5/6 ☜(ﾟヮﾟ☜) <<<<<<<<<<<<\n\n");
}
