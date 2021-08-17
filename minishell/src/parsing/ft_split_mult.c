/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:11:30 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/12 21:44:01 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	word_len(const char *str, char *delimits)
{
	size_t count;

	count = 0;
	while (str[count] != '\0' && !ft_strchr(delimits, str[count]))
		count++;
	return (count);
}

static char		*pos_next_word(char const *s, char *delimits)
{
	while (*s && ft_strchr(delimits, *s))
		s++;
	return ((char *)s);
}

static size_t	ft_countwords(const char *str, char *delimits)
{
	size_t	result;
	size_t	i;

	i = 0;
	result = 0;
	while (str[i] && !ft_strchr(delimits, str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && !ft_strchr(delimits, str[i]))
			i++;
		result++;
		while (str[i] && ft_strchr(delimits, str[i]))
			i++;
	}
	return (result);
}

static void		malloc_fuckedup(char **words, size_t pos)
{
	size_t i;

	i = 0;
	while (i <= pos)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char			**ft_split_mult(char const *s, char *delimits)
{
	size_t	num_words;
	char	**words;
	size_t	i;

	if (!s)
		return (NULL);
	num_words = ft_countwords(s, delimits);
	if (!(words = malloc((num_words + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		s = pos_next_word(s, delimits);
		words[i] = ft_substr(s, 0, word_len(s, delimits));
		if (words[i] == NULL)
		{
			malloc_fuckedup(words, i);
			return (NULL);
		}
		i++;
		s += word_len(s, delimits);
	}
	words[num_words] = NULL;
	return (words);
}
