/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:59:35 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/13 12:12:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	djb2 hashing algorithm
*	More info:http://www.cse.yorku.ca/~oz/hash.html
*/

unsigned long int	hash(char *key, unsigned int size)
{
	unsigned long int	hash;
	unsigned int		i;

	hash = 5381;
	i = 0;
	while (key && key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash % size);
}

void	display_hashmap_bucket(t_hashmap *bucket)
{
	unsigned int		index;
	t_hashmap_item		*current;

	index = 0;
	ft_putendl_fd("***********************", 1);
	while (index < bucket->size)
	{
		current = bucket->items[index];
		while (current)
		{
			ft_putstr_fd("* ", 1);
			ft_putstr_fd(current->key, 1);
			ft_putstr_fd(" : ", 1);
			ft_putendl_fd(current->value, 1);
			current = current->next;
		}
		index++;
	}
	ft_putendl_fd("***********************", 1);
}

void	handle_hashmap_collision(
			t_hashmap *bucket,
			unsigned long int index,
			t_hashmap_item *new_item)
{
	t_hashmap_item	*current;

	current = bucket->items[index];
	while (current->next)
	{
		if (ft_strcmp(current->next->key, new_item->key) == 0)
		{
			free(current->next->value);
			current->next->value = NULL;
			if (new_item->value)
				current->next->value = ft_strdup(new_item->value);
			free_hashmap_item(new_item);
			return ;
		}
		current = current->next;
	}
	current->next = new_item;
	current->next->next = NULL;
	(bucket->count)++;
}
