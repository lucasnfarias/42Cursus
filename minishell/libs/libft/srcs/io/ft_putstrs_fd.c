/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 07:21:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 13:06:23 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_putstrs_fd(char **strs, int fd)
{
	size_t	index;
	size_t	len;
	char	*full;

	if (!strs || !*strs)
		return ;
	index = -1;
	len = 0;
	while (strs[++index])
		len += ft_strlen(strs[index]);
	if (!len)
		return ;
	len++;
	full = ft_calloc(len, sizeof(char));
	if (!full)
		return ;
	index = -1;
	while (strs[++index])
		ft_strlcat(full, strs[index], len);
	write(fd, full, len - 1);
	free(full);
}
