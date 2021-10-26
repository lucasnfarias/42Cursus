/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:32:52 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 21:48:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	execute_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return ((echo_builtin(argv), true));
	if (ft_strcmp(argv[0], "cd") == 0)
		return ((cd_builtin(argv), true));
	if (ft_strcmp(argv[0], "pwd") == 0)
		return ((pwd_builtin(), true));
	if (ft_strcmp(argv[0], "export") == 0)
		return ((export_builtin(argv), true));
	if (ft_strcmp(argv[0], "unset") == 0)
		return ((unset_builtin(argv), true));
	if (ft_strcmp(argv[0], "env") == 0)
		return ((env_builtin(), true));
	if (ft_strcmp(argv[0], "exit") == 0)
		return ((exit_builtin(argv), true));
	return (false);
}

static void	execute_external(char **argv)
{
	char	**env;
	char	*temp;
	char	*path;

	temp = NULL;
	path = find_command_path(&temp, argv[0]);
	env = hashmap_env_to_array_env(g_minishell.env, path);
	if (!path || !env || execve(path, argv, env) == -1)
	{
		if (ft_strchr(argv[0], '/') || !temp)
		{
			if (access(argv[0], F_OK) != 0)
				error_handler(argv[0], "No such file or directory", 127);
			else if (is_directory(argv[0]))
				error_handler(argv[0], "Is a directory", 126);
			else if (access(argv[0], X_OK) != 0 )
				error_handler(argv[0], "Permission denied", 126);
		}
		else if (!path)
			error_handler(argv[0], "command not found", 127);
		free_str_array(env);
		free(path);
		free(temp);
		exit(g_minishell.error_status);
	}
}

static bool	set_variables(t_command *command)
{
	t_dlist	*var;

	if (command->words)
		return (false);
	var = command->variables;
	while (var)
	{
		set_variable(var->content);
		var = var->next;
	}
	g_minishell.error_status = 0;
	return (true);
}

pid_t	execute_program(t_command *command)
{
	pid_t	pid;
	char	**argv;

	pid = 0;
	if (set_variables(command))
		return (pid);
	argv = str_list_array(command->words);
	if (execute_builtin(argv))
		return ((free_str_array(argv), pid));
	if (command->op != TD_PIPE)
		pid = fork();
	if (pid == -1)
		exit_minishell();
	set_exec_signals();
	if (pid == 0)
	{
		execute_external(argv);
	}
	free_str_array(argv);
	return (pid);
}
