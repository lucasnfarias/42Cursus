/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_formater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 08:53:05 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*format_path(char **folders);

static bool	split_and_organize_path_node(
	char *part,
	char **folders,
	size_t *position)
{
	char	*path;

	if (!ft_strcmp("..", part) || !ft_strcmp(".", part))
	{
		if (!ft_strcmp(".", part) || !*position)
			return (true);
		(*position)--;
		free(folders[*position]);
		folders[*position] = NULL;
		return (true);
	}
	folders[*position] = ft_strdup(part);
	(*position)++;
	path = format_path(folders);
	if (!is_directory(path))
	{
		free(path);
		return (false);
	}
	free(path);
	return (true);
}

static char	**split_and_organize_path(char *path)
{
	size_t	index;
	size_t	position;
	char	**folders;
	char	**parts;

	index = -1;
	position = 0;
	parts = ft_split(path, '/');
	folders = ft_calloc(ft_count_segment(path, '/') + 1, sizeof(char *));
	while (parts[++index])
		if (!split_and_organize_path_node(parts[index], folders, &position))
			break ;
	free_str_array(parts);
	return (folders);
}

static char	*format_path(char **folders)
{
	int				index;
	t_str_builder	*builder;
	char			*path;

	index = -1;
	builder = str_builder_init();
	str_builder_add_char(builder, '/');
	while (folders[++index])
	{
		str_builder_add_str(builder, folders[index]);
		if (folders[index + 1])
			str_builder_add_char(builder, '/');
	}
	path = ft_strdup(builder->str);
	str_builder_destroy(builder);
	return (path);
}

static char	*remove_slash_path(char *path)
{
	t_str_builder	*builder;
	int				index;

	if (!path)
		return (NULL);
	index = 0;
	builder = str_builder_init();
	while (path[index])
	{
		if (path[index] != '/' || (path[index] == '/' && path[index + 1]))
			str_builder_add_char(builder, path[index]);
		while (path[index] == '/' && path[index + 1] == '/')
			index++;
		index++;
	}
	path = ft_strdup(builder->str);
	str_builder_destroy(builder);
	return (path);
}

char	*join_path(char *a, char *b)
{
	t_str_builder	*builder;
	char			**parts;

	builder = str_builder_init();
	if (*b != '/')
	{
		str_builder_add_str(builder, a);
		str_builder_add_char(builder, '/');
	}
	str_builder_add_str(builder, b);
	a = remove_slash_path(builder->str);
	parts = split_and_organize_path(a);
	free(a);
	b = format_path(parts);
	free_str_array(parts);
	str_builder_destroy(builder);
	return (b);
}
