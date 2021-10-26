/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:42:28 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:23:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!dst)
		return (ft_strdup(""));
	ft_strlcpy(dst, s1, s1_len + 1);
	ft_strlcat(dst, s2, s1_len + s2_len + 1);
	return (dst);
}
