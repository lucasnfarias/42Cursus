/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 09:33:04 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/14 07:34:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "libft.h"

# include <unistd.h>

void	ft_putchar_fd(unsigned int c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);
int		get_next_line(int fd, char **line);
void	ft_putstrs_fd(char **strs, int fd);

#endif
