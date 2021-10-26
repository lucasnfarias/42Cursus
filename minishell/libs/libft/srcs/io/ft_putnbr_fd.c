/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:05:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/14 07:32:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (!nbr)
		return ;
	write(fd, nbr, ft_strlen(nbr));
	free(nbr);
}
