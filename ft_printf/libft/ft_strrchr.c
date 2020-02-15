/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:58:49 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/22 18:36:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	letra;

	letra = (char)c;
	len = ft_strlen((char*)s);
	while (len > 0)
	{
		if (*(s + len - 1) == c)
			return ((char*)(s + len - 1));
		else
			--len;
	}
	if (letra == '\0')
	{
		len = ft_strlen((char*)s);
		return ((char*)(s + len));
	}
	return (NULL);
}
