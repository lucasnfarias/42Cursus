/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:01:43 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/14 07:32:17 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*endl;

	if (!s)
		return ;
	endl = ft_strjoin(s, "\n");
	if (!endl)
		return ;
	write(fd, endl, ft_strlen(endl));
	free(endl);
}
