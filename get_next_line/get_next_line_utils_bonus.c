/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:17:00 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/31 15:17:03 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*(ptr1++) = *(ptr2++);
		n--;
	}
	return (dst);
}
