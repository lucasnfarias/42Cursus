/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:08:51 by lniehues          #+#    #+#             */
/*   Updated: 2021/03/05 11:00:22 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libasm.h"
#include "libtests.h"

void	strlen_test_print(char *str)
{
	printf("`%s`\n\n=> FT: %d x ORIGINAL: [%d]\n", str,
		(int)ft_strlen(str), (int)strlen(str));
	printf("\n#################### \n\n");
}

void	strcpy_test_print(char *ft_dest, char *dest, char *src)
{
	printf("=> FT: `%s`\n\n=> ORIGINAL: [`%s`]\n\n=> SRC: (%s)\n",
		ft_strcpy(ft_dest, src), strcpy(dest, src), src);
	printf("\n#################### \n\n");
}

void	strcmp_test_print(char *s1, char *s2)
{
	printf("=> S1: `%s`\n\n=> S2: `%s`\n\n=> RESULT = FT: %d x ORIGINAL: \
[%d]\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("\n####################\n\n");
}

void	write_test_print(int ft_fd, int fd, char *buf, size_t bytes)
{
	printf("# FT_WRITE\n=> RESULT(bytes written): %ld -> (`%s`: %zu)\n",
		ft_write(ft_fd, buf, bytes), buf, bytes);
	printf("errno: %d - %s\n\n", errno, strerror(errno));
	printf("# WRITE\n=> RESULT(bytes written): %ld -> (`%s`: %zu)\n",
		write(fd, buf, bytes), buf, bytes);
	printf("errno: %d - %s\n\n", errno, strerror(errno));
	printf("#################### \n\n");
}

void	read_test_print(int *fds, char *ft_buf, char *buf, size_t bytes)
{
	ssize_t	r;

	r = 0;
	r = ft_read(fds[0], ft_buf, bytes);
	printf("1. FT_READ\n=> RESULT (text read): `%s`\n\n=> BYTES READ: %ld \
bytes\n\n", ft_buf, r);
	printf("errno: %d - %s\n\n", errno, strerror(errno));
	r = read(fds[1], buf, bytes);
	printf("2. READ\n=> RESULT (text read): `%s`\n\n=> BYTES READ: %ld \
bytes\n\n", buf, r);
	printf("errno: %d - %s\n", errno, strerror(errno));
	printf("\n####################\n\n");
}
