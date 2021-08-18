/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:13:41 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/24 23:19:06 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define UTF8_CP1 0x80
#define UTF8_BX 0x80
#define UTF8_B2 0xC0

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	chr;

	if ((unsigned char)c >= UTF8_CP1)
	{
		chr = (unsigned char)c / 0x40 + UTF8_B2;
		write(fd, &chr, 1);
		chr = (unsigned char)c % 0x40 + UTF8_BX;
		write(fd, &chr, 1);
	}
	else
		write(fd, &c, sizeof(char));
}
