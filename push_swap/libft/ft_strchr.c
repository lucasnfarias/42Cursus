/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:31 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:03:51 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	let;

	let = (char)c;
	while (*s != '\0')
	{
		if (*s == let)
			return ((char *)s);
		else
			++s;
	}
	if (let == '\0')
		return ((char *)s);
	return (NULL);
}
