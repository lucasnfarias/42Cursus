/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:29:38 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 22:00:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*dst;

	if (!s || !f)
		return (0);
	index = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (0);
	while (s[index])
	{
		dst[index] = f(index, s[index]);
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
