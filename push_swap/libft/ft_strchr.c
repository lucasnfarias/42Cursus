/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:31 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/17 21:40:29 by lniehues         ###   ########.fr       */
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
			return ((char*)s);
		else
			++s;
	}
	if (let == '\0')
		return ((char*)s);
	return (NULL);
}
