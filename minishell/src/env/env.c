/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:24:32 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/18 19:50:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(t_hashmap *env)
{
	unsigned int	index;
	t_hashmap_item	*current;
	char			*temp;

	index = 0;
	while (index < env->size)
	{
		current = env->items[index];
		while (current)
		{
			ft_putstr_fd(current->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			if (!ft_strcmp("_", current->key))
			{
				temp = getcwd(NULL, 0);
				ft_putstr_fd(temp, STDOUT_FILENO);
				free(temp);
			}
			else
				ft_putstr_fd(current->value, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			current = current->next;
		}
		index++;
	}
}

char	*find_env(char *key)
{
	if (*key == '?')
		return (ft_itoa(g_minishell.error_status));
	return (find_hashmap_value(g_minishell.env, key));
}

t_hashmap	*env_to_hashmap(char *const env[])
{
	int			i;
	t_hashmap	*parsed_env;
	char		*equal;
	char		*tmp;

	i = 0;
	while (env[i])
		i++;
	parsed_env = create_hashmap_bucket(i * 2);
	i = -1;
	while (env[++i])
	{
		tmp = ft_strdup(env[i]);
		equal = ft_strchr(tmp, '=');
		tmp[equal - tmp] = '\0';
		insert_on_hashmap(tmp, equal + 1, parsed_env);
		free(tmp);
	}
	return (parsed_env);
}

static char	*item_to_env_entry(t_hashmap_item *item, char *path)
{
	char			*entry;
	t_str_builder	*builder;

	builder = str_builder_init();
	str_builder_add_str(builder, item->key);
	str_builder_add_char(builder, '=');
	if (!ft_strcmp("_", item->key))
		str_builder_add_str(builder, path);
	else
		str_builder_add_str(builder, item->value);
	entry = ft_strdup(builder->str);
	str_builder_destroy(builder);
	return (entry);
}

char	**hashmap_env_to_array_env(t_hashmap *bucket, char *path)
{
	unsigned int	i;
	unsigned int	j;
	t_hashmap_item	*current;
	char			**env;

	i = 0;
	j = 0;
	env = ft_calloc(sizeof (char *), bucket->count + 1);
	while (i < bucket->size && j < bucket->count)
	{
		current = bucket->items[i];
		while (current != NULL)
		{
			env[j] = item_to_env_entry(current, path);
			current = current->next;
			j++;
		}
		i++;
	}
	return (env);
}
