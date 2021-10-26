/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:39:34 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 12:41:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_std_fd(void)
{
	g_minishell.fd_in = dup(STDIN_FILENO);
	g_minishell.fd_out = dup(STDOUT_FILENO);
	g_minishell.fd_err = dup(STDERR_FILENO);
	g_minishell.fd_null = open("/dev/null", O_RDONLY | O_WRONLY);
}

void	restore_std_fd(void)
{
	dup2(g_minishell.fd_in, STDIN_FILENO);
	dup2(g_minishell.fd_out, STDOUT_FILENO);
	dup2(g_minishell.fd_err, STDERR_FILENO);
}

void	null_std_fd(void)
{
	dup2(g_minishell.fd_null, STDIN_FILENO);
	dup2(g_minishell.fd_null, STDOUT_FILENO);
	dup2(g_minishell.fd_null, STDERR_FILENO);
}

void	close_std_fd(void)
{
	close(g_minishell.fd_in);
	close(g_minishell.fd_out);
	close(g_minishell.fd_err);
}
