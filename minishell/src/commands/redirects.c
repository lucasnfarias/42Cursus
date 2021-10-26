/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:45:10 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 15:51:46 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	redirect_heredoc(char *content)
{
	int	*fd;

	fd = pipe_create();
	ft_putstr_fd(content, fd[1]);
	pipe_set_reader(&fd);
	return (true);
}

static bool	redirect_file(char *file, int stdfd, int flag)
{
	int	fd;

	fd = open(file, flag, 0644);
	if (fd == -1)
	{
		error_handler(file, strerror(errno), 1);
		return (false);
	}
	if (dup2(fd, stdfd) == -1)
		exit_minishell();
	close(fd);
	return (true);
}

static bool	configure_redirect_node(t_token *redirect)
{
	if (redirect->id == TD_HERE_DOCUMENT)
		return (redirect_heredoc(redirect->value));
	if (redirect->id == TD_INPUT)
		return (redirect_file(redirect->value, STDIN_FILENO, O_RDONLY));
	if (redirect->id == TD_APPEND_MODE)
		return (redirect_file(redirect->value,
				STDOUT_FILENO, O_WRONLY | O_CREAT | O_APPEND));
	if (redirect->id == TD_OUTPUT)
		return (redirect_file(
				redirect->value, STDOUT_FILENO,
				O_WRONLY | O_CREAT | O_TRUNC));
	return (false);
}

pid_t	configure_redirect(t_command *command)
{
	t_dlist	*redirect;

	redirect = command->redirects;
	while (redirect)
	{
		if (!configure_redirect_node(redirect->content))
		{
			if (command->op == TD_PIPE)
				exit(g_minishell.error_status);
			return (0);
		}
		redirect = redirect->next;
	}
	return (execute_program(command));
}
