/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:49:21 by msales-a          #+#    #+#             */
/*   Updated: 2020/05/23 10:44:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(char const *big, const char *little, size_t len)
{
	size_t	index;
	size_t	length;

	if (!*little)
		return ((char *)big);
	index = 0;
	length = ft_strlen(little);
	while (*big && index + length <= len)
	{
		if (!big || !little || ft_strncmp(big, little, length) == 0)
			return ((char *)big);
		big++;
		index++;
	}
	return (0);
}
