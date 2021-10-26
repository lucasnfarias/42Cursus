/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:25:36 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/26 19:25:46 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strstr(char const *haystack, const char *needle)
{
	size_t	needle_size;
	size_t	haystack_size;

	if (!*needle || !haystack)
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	haystack_size = ft_strlen(haystack);
	while (*haystack && needle_size <= haystack_size)
	{
		if (ft_strncmp(haystack, needle, needle_size) == 0)
			return ((char *)haystack);
		haystack++;
		haystack_size--;
	}
	return (NULL);
}
