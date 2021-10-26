/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:04:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:19:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char const	*ps;

	ps = s;
	while (n--)
		if (*(ps++) == (unsigned char)c)
			return ((void *)--ps);
	return (NULL);
}
