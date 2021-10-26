/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:43:43 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:32:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strrchr(char const *s, int c)
{
	int	index;

	index = ft_strlen(s) + 1;
	while (index--)
	{
		if (s[index] == c)
			return ((char *)s + index);
	}
	return (0);
}
