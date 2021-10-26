/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:46:07 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 16:58:10 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler_sigint(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', STDOUT_FILENO);
	exit(2);
}

static void	doc_writer(int fd, char *value, int heredoc_line)
{
	char	*line;

	signal(SIGINT, handler_sigint);
	while (true)
	{
		read_input("> ", &line);
		if (!line)
		{
			error_heredoc_eof(value, heredoc_line);
			if (g_minishell.interactive)
				exit(1);
			break ;
		}
		g_minishell.general_line++;
		if (ft_strcmp(value, line) == 0)
			break ;
		ft_putendl_fd(line, fd);
		free(line);
	}
	if (line)
		free(line);
	if (g_minishell.interactive)
		exit(0);
}

static char	*doc_reader(int fd)
{
	bool			read_something;
	char			*line;
	t_str_builder	*builder;

	builder = str_builder_init();
	read_something = false;
	while (true)
	{
		if (get_next_line(fd, &line) <= 0)
		{
			free(line);
			break ;
		}
		g_minishell.heredoc_line++;
		str_builder_add_str(builder, line);
		str_builder_add_char(builder, '\n');
		free(line);
		read_something = true;
	}
	if (!read_something)
		g_minishell.heredoc_line++;
	line = ft_strdup(builder->str);
	str_builder_destroy(builder);
	return (line);
}

int	*haredoc_(char *value, int *exit_code)
{
	pid_t	pid;
	int		*fd;

	pid = 0;
	fd = pipe_create();
	if (g_minishell.interactive)
		pid = fork();
	if (pid == -1)
		return (NULL);
	if (pid == 0)
		doc_writer(fd[1], value, g_minishell.heredoc_line);
	close(fd[1]);
	waitpid(pid, exit_code, 0);
	return (fd);
}

char	*heredoc(char *value)
{
	int		*fd;
	int		exit_code;
	char	*line;

	fd = haredoc_(value, &exit_code);
	line = doc_reader(fd[0]);
	close(fd[0]);
	if (WIFEXITED(exit_code) && WEXITSTATUS(exit_code) > 1)
	{
		g_minishell.error_status = 130;
		pipe_free(&fd);
		free(line);
		return (NULL);
	}
	pipe_free(&fd);
	g_minishell.error_status = 0;
	return (line);
}
