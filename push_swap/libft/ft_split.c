/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:11:30 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:03:09 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_len(const char *str, char sep)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != sep)
		count++;
	return (count);
}

static char	*pos_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static size_t	ft_countwords(const char *str, char sep)
{
	size_t	result;
	size_t	i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		result++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (result);
}

static void	malloc_fuckedup(char **words, size_t pos)
{
	size_t	i;

	i = 0;
	while (i <= pos)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**words;
	size_t	i;

	if (!s)
		return (NULL);
	num_words = ft_countwords(s, c);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		s = pos_next_word(s, c);
		words[i] = ft_substr(s, 0, word_len(s, c));
		if (words[i] == NULL)
		{
			malloc_fuckedup(words, i);
			return (NULL);
		}
		i++;
		s += word_len(s, c);
	}
	words[num_words] = NULL;
	return (words);
}
