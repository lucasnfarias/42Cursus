/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:16:08 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/28 12:54:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	ptrdst = (unsigned char*)dst;
	ptrsrc = (unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (*ptrdst == *ptrsrc)
		return (dst);
	if (ptrsrc < ptrdst)
		while (++i <= len)
			ptrdst[len - i] = ptrsrc[len - i];
	else
		while (len-- > 0)
			*(ptrdst++) = *(ptrsrc++);
	return (dst);
}
