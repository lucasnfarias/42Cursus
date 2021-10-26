/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:22:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:44:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		index;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	index = 0;
	while (s[start + index] && index < (int)len)
	{
		dest[index] = *(s + start + index);
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
