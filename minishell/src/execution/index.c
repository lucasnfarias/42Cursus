/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:18:47 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/13 22:02:11 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	run_system_cmd(char **cmd, char **env)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		printf("%s", strerror(11));
		exit(11);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			printf("minishell : %s : %s\n", strerror(errno), cmd[0]);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		// if (bg) child in background
		// else 
		wait(&child_pid);
	}
}

// int main(void)
// {
// 	pid_t	pid_id;
// 	char	*argv[] = { "/bin/ls", NULL };
// 	char	*envp[] = { "test=test", NULL };

// 	pid_id = fork();

// 	if (pid_id < 0)
// 		exit(11);
// 	else if (pid_id == 0)
// 	{
// 		if (execve(argv[0], argv, envp) < 0)
// 		{
// 			printf("%s: Error. %s", "ls", strerror(errno));
// 			exit(0);
// 		}
// 	}
// 	else
// 	{
// 		wait(&pid_id);
// 	}
// }