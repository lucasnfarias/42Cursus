/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:37:22 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/29 12:56:21 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	size_t	pos;
	size_t	z;

	pos = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[pos] != '\0' && pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			z = 1;
			while (needle[z] != '\0' && haystack[pos + z] == needle[z]
					&& (pos + z) < len)
				z++;
			if (needle[z] == '\0')
			{
				haystack = &haystack[pos];
				return ((char*)haystack);
			}
		}
		pos++;
	}
	return (0);
}
