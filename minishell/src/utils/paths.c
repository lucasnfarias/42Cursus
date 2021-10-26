/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:47:09 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/19 08:57:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_home_value(void)
{
	char			*home;
	t_str_builder	*builder;

	home = find_env("HOME");
	if (!home)
	{
		builder = str_builder_init();
		str_builder_add_str(builder, "/home/");
		str_builder_add_str(builder, getenv("USER"));
		home = ft_strdup(builder->str);
		str_builder_destroy(builder);
	}
	return (home);
}

static char	*get_tilde_value(char *path, int *index)
{
	char	*value;

	*index = 0;
	value = NULL;
	if (!ft_strncmp("~+", path, 2))
	{
		value = find_env("PWD");
		*index = 2;
	}
	else if (!ft_strncmp("~-", path, 2))
	{
		value = find_env("OLDPWD");
		if (!value)
			value = ft_strdup("~-");
		*index = 2;
	}
	else if (path[0] == '~' && path[1] != '~')
	{
		value = get_home_value();
		*index = 1;
	}
	return (value);
}

char	*resolve_tilde(char *path)
{
	t_str_builder	*builder;
	char			*temp;
	int				index;

	if (!path)
		return (NULL);
	builder = str_builder_init();
	temp = get_tilde_value(path, &index);
	str_builder_add_str(builder, temp);
	free(temp);
	path += index;
	str_builder_add_str(builder, path);
	temp = ft_strdup(builder->str);
	str_builder_destroy(builder);
	return (temp);
}

void	cwd_setup(void)
{
	char	*path;

	path = find_env("PATH");
	if (!path || !is_directory(path) || access(path, F_OK | X_OK))
	{
		free(path);
		path = getcwd(NULL, 0);
		insert_on_hashmap("PWD", path, g_minishell.env);
		g_minishell.pwd = path;
	}
}
