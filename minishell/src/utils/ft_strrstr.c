/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:43:14 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/22 21:01:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strrstr(char const *big, const char *little)
{
	size_t	i;
	size_t	len;

	if (!big || !*big || !little || !*little)
		return ((char *)big);
	len = ft_strlen(little);
	i = ft_strlen(big);
	while (i >= 0 && i >= len)
	{
		if (ft_strncmp(big + i - len, little, len) == 0)
			return ((char *)big + i - len);
		i--;
	}
	return (0);
}
