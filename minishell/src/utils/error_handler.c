/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:59 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 23:29:26 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_handler_arg(char *cmd, char *arg, char *msg, int status)
{
	char	*line;

	g_minishell.error_status = status;
	line = ft_itoa(g_minishell.general_line);
	if (g_minishell.interactive)
	{
		ft_putstrs_fd((char *[]){"minishell: ", cmd, ": ", arg, ": ",
			msg, "\n", NULL}, STDERR_FILENO);
	}
	else
	{
		ft_putstrs_fd((char *[]){"minishell: line ", line, ": ",
			cmd, ": ", arg, ": ", msg, "\n", NULL}, STDERR_FILENO);
	}
	free(line);
}

void	error_handler(char *cmd, char *msg, int status)
{
	char	*line;

	g_minishell.error_status = status;
	line = ft_itoa(g_minishell.general_line);
	if (g_minishell.interactive)
	{
		ft_putstrs_fd((char *[]){
			"minishell: ", cmd, ": ", msg, "\n", NULL}, STDERR_FILENO);
	}
	else
	{
		ft_putstrs_fd((char *[]){"minishell: line ", line, ": ",
			cmd, ": ", msg, "\n", NULL}, STDERR_FILENO);
	}
	free(line);
}

void	error_simple(char *msg, int status)
{
	char	*line;

	g_minishell.error_status = status;
	line = ft_itoa(g_minishell.general_line);
	if (g_minishell.interactive)
	{
		ft_putstrs_fd((char *[]){
			"minishell: `", msg, "'\n", NULL}, STDERR_FILENO);
	}
	else
	{
		ft_putstrs_fd((char *[]){"minishell: line ", line, ": `",
			msg, "'\n", NULL}, STDERR_FILENO);
	}
	free(line);
}

void	error_heredoc_eof(char *value, int heredoc_line)
{
	char	*gline;
	char	*hline;

	gline = ft_itoa(g_minishell.general_line);
	hline = ft_itoa(heredoc_line + 1);
	if (g_minishell.interactive)
	{
		ft_putstrs_fd((char *[]){"minishell: warning: here-document at line ",
			hline, " delimited by end-of-file (wanted `", value, "')\n", NULL},
			STDERR_FILENO);
	}
	else
	{
		ft_putstrs_fd((char *[]){"minishell: line ", gline,
			": warning: here-document at line ", hline,
			" delimited by end-of-file (wanted `", value, "')\n", NULL},
			STDERR_FILENO);
	}
	free(gline);
	free(hline);
}

void	syntax_error(t_token *token)
{
	char				*gline;
	t_token_definition	*tokens;

	gline = ft_itoa(g_minishell.general_line);
	tokens = (t_token_definition[]){
	{.id = TD_HERE_DOCUMENT, .value = "<<"}, {.id = TD_AND, .value = "&&"},
	{.id = TD_OR, .value = "||"}, {.id = TD_APPEND_MODE, .value = ">>"},
	{.id = TD_PIPE, .value = "|"}, {.id = TD_OUTPUT, .value = ">"},
	{.id = TD_INPUT, .value = "<"}, {.id = TD_DOUBLE_QUOTE, .value = "\""},
	{.id = TD_SINGLE_QUOTE, .value = "'"}, {.id = TD_SPACE, .value = " "},
	{.id = TD_ESCAPE, .value = "\\"},
	{.id = TD_NEWLINE, .value = "newline"}, {.id = TD_UNKNOWN}};
	while (tokens->id != TD_NEWLINE && (!token || tokens->id != token->id))
		tokens++;
	if (g_minishell.interactive)
		ft_putstrs_fd((char *[]){
			"minishell: syntax error near unexpected token `", tokens->value,
			"'\n", NULL}, STDERR_FILENO);
	else
		ft_putstrs_fd((char *[]){"minishell: line ", gline,
			": syntax error near unexpected token `", tokens->value,
			"'\n", NULL}, STDERR_FILENO);
	free(gline);
}
