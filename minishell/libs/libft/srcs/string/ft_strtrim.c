/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:52:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 22:02:11 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int	index;
	int	start;
	int	end;

	if (!s || !set)
		return (0);
	index = 0;
	while (ft_strchr(set, s[index]) && s[index])
		index++;
	start = index;
	if (!s[start])
		return (ft_strdup(""));
	index = ft_strlen(s);
	while (ft_strchr(set, s[index]) && index)
		index--;
	end = index;
	return (ft_substr(s, start, end - start + 1));
}
