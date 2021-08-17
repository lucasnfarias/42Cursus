/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:24:37 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/13 21:55:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_tokens(t_cmd *cmd)
{
	int	i;
	char	*envp[] = { "test=test", NULL };

	i = 0;
	while (cmd->argv[i])
	{
		printf("%s | ", cmd->argv[i]);
		i++;
	}
	printf("\nLength: %d\n", cmd->argc);
	if (cmd->builtin == NONE)
		run_system_cmd(cmd->argv, envp);
	// else run_builtin_cmd();
	free_tokens(cmd->argv);
}

int	read_cmd(char **line)
{
	int	ret;

	ret = 0;
	*line = (char *)ft_calloc(BUFF_SIZE, sizeof(char));
	if (!line)
	{
		ft_putendl_fd("\e[1;31mminiHell$ : allocation error\e[0;37m", STDOUT);
		exit(1);
	}
	ret = read(STDIN, *line, BUFF_SIZE);
	if (ret == -1)
	{
		if (line[BUFF_SIZE] == 0)
			exit(0);
		else
			exit(1);
	}
	return (ret);
}

char	**tokenize(char *cmdline)
{
	char delimits[10] = " \n\t\r";

	return (ft_split_mult(cmdline, delimits));
}

static int		array_length(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

static int parse_builtin(t_cmd *cmd)
{
	if (strncmp(cmd->argv[0], "ls", 10) == 0)
		return (0);
	return (0);
}

int		parse_cmdline(char *cmdline, t_cmd *cmd)
{
	int is_bg;

	cmd->argv = tokenize(cmdline); // tokenize commands ls\r-l | grep\t"asd" -> ["ls", "-l", "|" , "grep", "asd"]
	cmd->argc = array_length(cmd->argv);
	cmd->builtin = parse_builtin(cmd);

	is_bg = ft_strncmp(cmd->argv[cmd->argc - 1], "&", 2) == 0;
	if (is_bg)
		cmd->argv[--cmd->argc] = NULL;
	parse_tokens(cmd);
	return (is_bg);
}

void	evaluate(char *cmdline)
{
	int bg;
	t_cmd	cmd;

	printf("Evaluating: %s", cmdline);

	bg = parse_cmdline(cmdline, &cmd);

	if (bg == -1) return; // handle error of parser
}
