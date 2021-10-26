/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:24:41 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/18 21:44:13 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	cmd_is_executable(char *cmd_path)
{
	struct stat	buffer;

	if (stat(cmd_path, &buffer) != 0)
		return (false);
	if (buffer.st_mode & __S_IFMT & __S_IFDIR)
		return (false);
	if (buffer.st_mode & S_IXUSR)
		return (true);
	return (false);
}

static char	*cmd_path_constructor(char *command, char *path)
{
	t_str_builder	*builder;
	char			*temp;

	builder = str_builder_init();
	str_builder_add_str(builder, path);
	str_builder_add_char(builder, '/');
	str_builder_add_str(builder, command);
	temp = ft_strdup(builder->str);
	str_builder_destroy(builder);
	return (temp);
}

static char	*find_command_path_node(char *path, char *command)
{
	int		i;
	char	**paths;
	char	*temp;

	if (!path)
		return (NULL);
	i = -1;
	paths = ft_split(path, ':');
	while (paths[++i])
	{
		temp = cmd_path_constructor(command, paths[i]);
		if (cmd_is_executable(temp))
			return ((free_str_array(paths), temp));
		free(temp);
	}
	free_str_array(paths);
	return (NULL);
}

char	*find_command_path(char **path, char *command)
{
	char	*temp;

	if (!command)
		return (NULL);
	if (ft_strchr(command, '/'))
	{
		if (cmd_is_executable(command))
			return (ft_strdup(command));
		return (NULL);
	}
	*path = find_hashmap_value(g_minishell.local_var, "PATH");
	if (!*path)
		*path = find_hashmap_value(g_minishell.env, "PATH");
	temp = find_command_path_node(*path, command);
	return (temp);
}
