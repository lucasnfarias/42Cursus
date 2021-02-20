/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:15:23 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/19 18:16:49 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This is a slight variation of ft_substr that works better with get_next_line.
** Libft memory allocations are commonly "protected" with a condition to return
** null if the allocation fails. This sometimes causes get_next_line to crash.
*/

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned	int	i;
	size_t			s_len;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup_gnl(""));
	sub = (char *)malloc((len + 1) * sizeof(*s));
	if (sub == 0)
		return (0);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
