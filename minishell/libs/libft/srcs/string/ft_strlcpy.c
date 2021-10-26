/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:38:09 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:44:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	int	index;
	int	src_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	if (!dst)
		return (0);
	index = 0;
	src_len = ft_strlen(src);
	while (src[index] && index < (int)dstsize - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_len);
}
