/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:37:22 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:08:38 by lniehues         ###   ########.fr       */
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
		return ((char *)haystack);
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
				return ((char *)haystack);
			}
		}
		pos++;
	}
	return (0);
}
