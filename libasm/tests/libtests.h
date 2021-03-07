/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:55:23 by lniehues          #+#    #+#             */
/*   Updated: 2021/03/04 23:26:41 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTESTS_H
# define LIBTESTS_H

void	test_ft_strcpy(void);
void	test_ft_strcmp(void);
void	test_ft_read(void);
void	test_ft_write(void);

void	strlen_test_print(char *str);
void	strcpy_test_print(char *ft_dest, char *dest, char *src);
void	strcmp_test_print(char *s1, char *s2);
void	write_test_print(int ft_fd, int fd, char *buf, size_t bytes);
void	read_test_print(int *fds, char *ft_buf, char *buf, size_t bytes);
void	strdup_test_print(char *tmp, char *tmp2, char *src);

#endif
