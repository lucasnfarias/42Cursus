/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:50:10 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 20:59:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_(char const *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strdup_(const char *s1)
{
	int		len;
	char	*ptr;

	len = ft_strlen_(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy_(ptr, s1, len + 1);
	return (ptr);
}

size_t	ft_strlcpy_(char *dst, char const *src, size_t dstsize)
{
	int	index;
	int	src_len;

	if (dstsize == 0)
		return (ft_strlen_(src));
	if (!dst)
		return (0);
	index = 0;
	src_len = ft_strlen_(src);
	while (src[index] && index < (int)dstsize - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_len);
}

char	*ft_strjoin_(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen_(s1);
	s2_len = ft_strlen_(s2);
	dst = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (!dst)
		return (ft_strdup_(""));
	ft_strlcpy_(dst, s1, s1_len + 1);
	ft_strlcpy_(dst + s1_len, s2, s1_len + s2_len + 1);
	return (dst);
}

char	*ft_substr_(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		index;

	if (!s)
		return (0);
	if (ft_strlen_(s) <= start)
		return (ft_strdup_(""));
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
