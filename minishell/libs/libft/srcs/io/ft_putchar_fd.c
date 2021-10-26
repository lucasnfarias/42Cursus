/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:41:21 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/22 09:18:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_putbyte_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putunicode_fd(unsigned int c, int fd)
{
	if (c <= 0x7f)
		ft_putbyte_fd((0x00 | ((c >> 00) & 0xff)), fd);
	else if (c <= 0x7ff)
	{
		ft_putbyte_fd((0xc0 | ((c >> 06) & 0x1f)), fd);
		ft_putbyte_fd((0x80 | ((c >> 00) & 0x3f)), fd);
	}
	else if (c <= 0xffff)
	{
		ft_putbyte_fd((0xe0 | ((c >> 12) & 0x0f)), fd);
		ft_putbyte_fd((0x80 | ((c >> 06) & 0x3f)), fd);
		ft_putbyte_fd((0x80 | ((c >> 00) & 0x3f)), fd);
	}
	else if (c <= 0x10ffff)
	{
		ft_putbyte_fd((0xf0 | ((c >> 18) & 0x07)), fd);
		ft_putbyte_fd((0x80 | ((c >> 12) & 0x3f)), fd);
		ft_putbyte_fd((0x80 | ((c >> 06) & 0x3f)), fd);
		ft_putbyte_fd((0x80 | ((c >> 00) & 0x3f)), fd);
	}
}

void	ft_putchar_fd(unsigned int c, int fd)
{
	ft_putbyte_fd(c, fd);
}
