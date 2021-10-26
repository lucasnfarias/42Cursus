/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:08:10 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 10:41:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_count_segment(char const *str, char c)
{
	int	segments;

	segments = 0;
	while (str && *str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			segments++;
		while (*str != c && *str)
			str++;
	}
	return (segments);
}

char	*ft_norepeat(char const *str, char const *repeating)
{
	int		len;
	int		index;
	char	*ptr;

	len = 0;
	index = 0;
	ptr = (char *)str;
	while (ptr && *ptr)
	{
		len += ((*ptr != *(ptr + 1) || !ft_strchr(repeating, *ptr)));
		ptr++;
	}
	ptr = (char *)malloc(sizeof(char) * len);
	while (str && *str)
	{
		if (*str != *(str + 1) || !ft_strchr(repeating, *str))
			ptr[index++] = *str;
		str++;
	}
	ptr[index] = '\0';
	return (ptr);
}

const char	*ft_strtok(char **dst, char const *src, char d)
{
	int	length;
	int	index;

	*dst = 0;
	if (!src)
		return (src);
	while (*src && d && *src == d)
		src++;
	length = 0;
	while (src[length] && src[length] != d)
		length++;
	*dst = (char *)malloc(sizeof(char) + (length + 1));
	if (!length || !*dst)
		return (src);
	index = -1;
	(*dst)[length] = '\0';
	while (++index < length)
		(*dst)[index] = (char)src[index];
	return (src + index);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		argc;
	int		index;

	if (!s)
		return (NULL);
	argc = ft_count_segment(s, c);
	strs = (char **)ft_calloc((argc + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	strs[argc] = 0;
	index = 0;
	while (*s && index < argc)
		s = ft_strtok(&(strs[index++]), s, c);
	return (strs);
}
