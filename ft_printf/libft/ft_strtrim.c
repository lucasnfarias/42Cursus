/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:58:36 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/23 14:45:31 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char		*null_term_str(char *new)
{
	if (!(new = malloc(sizeof(char) * 1)))
		return (NULL);
	new[0] = '\0';
	return (new);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	new_start;
	size_t	new_end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	new_start = i;
	new = NULL;
	if (new_start == ft_strlen(s1))
		return (null_term_str(new));
	if ((i = ft_strlen(s1) - 1))
		while (i > 0 && is_in_set(s1[i], set))
			i--;
	new_end = i;
	if (!(new = malloc(sizeof(char) * (new_end - new_start + 2))))
		return (NULL);
	i = 0;
	while (new_start <= new_end)
		new[i++] = s1[new_start++];
	new[i] = '\0';
	return (new);
}
