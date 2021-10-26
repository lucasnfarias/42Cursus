/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:19:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:20:27 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char const	*ps1;
	unsigned char const	*ps2;

	if (!n)
		return (0);
	ps1 = s1;
	ps2 = s2;
	while (n--)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
	}
	return (0);
}
