/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:49:35 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:31:15 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*subs;
	size_t		i;
	size_t		length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	subs = malloc((sizeof(char) * len) + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len && i + start < length)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
