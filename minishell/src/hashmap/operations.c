/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:35:14 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/13 12:11:02 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_remove_and_relink_item(
	t_hashmap *bucket,
	t_hashmap_item *current,
	char *key)
{
	t_hashmap_item	*temp;

	while (current->next)
	{
		if (ft_strcmp(current->next->key, key) == 0)
		{
			temp = current->next;
			current->next = current->next->next;
			free_hashmap_item(temp);
			(bucket->count)--;
			return ;
		}
		current = current->next;
	}
}

static void	free_item_head_and_relink(
	t_hashmap *bucket,
	t_hashmap_item *current,
	unsigned long int index)
{
	if (!current->next)
	{
		free_hashmap_item(current);
		bucket->items[index] = NULL;
	}
	else
	{
		bucket->items[index] = current->next;
		free_hashmap_item(current);
	}
	(bucket->count)--;
}

void	remove_from_hashmap(t_hashmap *bucket, char *key)
{
	unsigned long int	index;
	t_hashmap_item		*current;

	index = hash(key, bucket->size);
	current = bucket->items[index];
	if (!current)
		return ;
	if (ft_strcmp(current->key, key) == 0)
		free_item_head_and_relink(bucket, current, index);
	else
		find_remove_and_relink_item(bucket, current, key);
}

void	insert_on_hashmap(char *key, char *value, t_hashmap *bucket)
{
	unsigned long int		index;
	t_hashmap_item			*new_item;
	t_hashmap_item			*current;

	index = hash(key, bucket->size);
	new_item = create_hashmap_item(key, value);
	current = bucket->items[index];
	if (!current)
	{
		bucket->items[index] = new_item;
		(bucket->count)++;
	}
	else
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = NULL;
			if (value)
				current->value = ft_strdup(value);
			free_hashmap_item(new_item);
		}
		else
			handle_hashmap_collision(bucket, index, new_item);
	}
}

char	*find_hashmap_value(t_hashmap *bucket, char *key)
{
	unsigned long int	index;
	t_hashmap_item		*current;

	index = hash(key, bucket->size);
	current = bucket->items[index];
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			if (!current->value)
				return (NULL);
			return (ft_strdup(current->value));
		}
		current = current->next;
	}
	return (NULL);
}
