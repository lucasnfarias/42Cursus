/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:58:36 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:29:55 by lniehues         ###   ########.fr       */
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

static char	*null_term_str(char *new)
{
	new = malloc(sizeof(char) * 1);
	if (!new)
		return (NULL);
	new[0] = '\0';
	return (new);
}

static void	trim_tail(char const *s1, char const *set, size_t *i)
{
	if (*i)
		while (*i > 0 && is_in_set(s1[*i], set))
			(*i)--;
}

char	*ft_strtrim(char const *s1, char const *set)
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
	i = ft_strlen(s1) - 1;
	trim_tail(s1, set, &i);
	new_end = i;
	new = malloc(sizeof(char) * (new_end - new_start + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (new_start <= new_end)
		new[i++] = s1[new_start++];
	new[i] = '\0';
	return (new);
}
