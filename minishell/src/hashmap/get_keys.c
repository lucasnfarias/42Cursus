/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:31:39 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/13 11:31:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_keys(t_hashmap *bucket)
{
	char			**keyvalues;
	size_t			i_index;
	size_t			b_index;
	t_hashmap_item	*item;

	i_index = -1;
	b_index = -1;
	keyvalues = ft_calloc(bucket->count + 1, sizeof (char *));
	if (!keyvalues)
		return (NULL);
	while (++b_index < bucket->size)
	{
		item = bucket->items[b_index];
		while (item)
		{
			keyvalues[++i_index] = ft_strdup(item->key);
			item = item->next;
		}
	}
	return (keyvalues);
}
