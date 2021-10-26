/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:19:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/19 09:41:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_to_path(char *path)
{
	char	*temp;

	temp = join_path(g_minishell.pwd, path);
	if (chdir(temp) != 0 && ft_strchr(path, '>') == NULL)
	{
		free(temp);
		error_handler_arg("cd", path, strerror(errno), 1);
		return ;
	}
	path = find_hashmap_value(g_minishell.env, "PWD");
	insert_on_hashmap("OLDPWD", path, g_minishell.env);
	free(path);
	insert_on_hashmap("PWD", temp, g_minishell.env);
	free(g_minishell.pwd);
	g_minishell.pwd = temp;
	g_minishell.error_status = 0;
}

static void	go_to_oldpwd(char *arg)
{
	char	*oldpwd;

	oldpwd = find_env("OLDPWD");
	if (!oldpwd)
		error_handler("cd", "OLDPWD not set", 1);
	else
	{
		if (!ft_strcmp("-", arg))
			ft_putendl_fd(oldpwd, STDOUT_FILENO);
		change_to_path(oldpwd);
	}
	free(oldpwd);
}

static void	go_home(void)
{
	char	*home;

	home = find_env("HOME");
	if (!home)
		error_handler("cd", "HOME not set", 1);
	else
		change_to_path(home);
	free(home);
}

void	cd_builtin(char **argv)
{
	if (argv[1] && argv[2])
		error_handler("cd", TOO_MANY_ARGS, 1);
	else if (!argv[1] || !ft_strcmp("--", argv[1]))
		go_home();
	else if (argv[1] && (!ft_strcmp("-", argv[1])))
		go_to_oldpwd(argv[1]);
	else if (argv[1] && *argv[1] == '-')
	{
		error_handler_arg("cd", argv[1], "invalid option", 2);
		ft_putstr_fd("cd: usage: cd [-L|[-P [-e]] [-@]] [dir]\n", STDERR_FILENO);
	}
	else if (argv[1])
		change_to_path(argv[1]);
}
