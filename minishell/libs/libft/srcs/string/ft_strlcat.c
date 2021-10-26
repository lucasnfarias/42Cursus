/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:56:27 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:37:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strnlen(dst, dstsize);
	if (dstlen == dstsize)
		return (dstsize + ft_strlen(src));
	srclen = ft_strnlen(src, dstsize - dstlen - 1);
	ft_strlcpy(dst + dstlen, src, srclen + 1);
	return (dstlen + ft_strlen(src));
}
