/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:43:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/13 13:59:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	handler_variable(t_command *command, t_dlist **tokens)
{
	t_token	*token;
	char	*value;

	token = (*tokens)->content;
	if (token->id != TD_WORD || !ft_isalpha(*token->value)
		|| !ft_strchr(token->value, '=') || command->words)
		return (false);
	value = expand_and_join_words(tokens);
	ft_dlstadd_back(&command->variables, ft_dlstnew(value));
	return (true);
}

static bool	handler_redirect(t_command *command, t_dlist **tokens)
{
	t_token	*token;
	char	*value;

	token = (*tokens)->content;
	if (token->id != TD_INPUT && token->id != TD_OUTPUT
		&& token->id != TD_APPEND_MODE && token->id != TD_HERE_DOCUMENT)
		return (false);
	if (token->id == TD_HERE_DOCUMENT)
	{
		add_token_to_result(&command->redirects, token->id, token->value);
		*tokens = (*tokens)->next;
		return (true);
	}
	*tokens = next_token_non_space(*tokens);
	value = expand_and_join_words(tokens);
	add_token_to_result(&command->redirects, token->id, value);
	free(value);
	return (true);
}

static bool	handler_word(t_command *command, t_dlist **tokens)
{
	t_token	*token;
	char	*value;

	token = (*tokens)->content;
	if (token->id != TD_WORD && token->id != TD_SINGLE_QUOTE
		&& token->id != TD_DOUBLE_QUOTE && token->id != TD_SPACE)
		return (false);
	if (token->id == TD_SPACE)
	{
		*tokens = (*tokens)->next;
		return (true);
	}
	value = expand_and_join_words(tokens);
	ft_dlstadd_back(&command->words, ft_dlstnew(value));
	return (true);
}

static bool	handler_op(t_command *command, t_dlist **tokens)
{
	t_token	*token;

	token = (*tokens)->content;
	if (token->id != TD_PIPE && token->id != TD_AND && token->id != TD_OR)
		return (false);
	command->op = token->id;
	*tokens = (*tokens)->next;
	return (true);
}

t_command	*get_next_command(t_dlist **tokens)
{
	int					index;
	t_command			*command;
	t_command_handler	*handlers;

	if (!tokens || !*tokens)
		return (NULL);
	command = command_init();
	handlers = (t_command_handler[]){
		handler_variable, handler_redirect, handler_word, handler_op, NULL};
	while (*tokens && !command->op)
	{
		index = 0;
		while (handlers[index] && !handlers[index](command, tokens))
			index++;
	}
	return (command);
}
