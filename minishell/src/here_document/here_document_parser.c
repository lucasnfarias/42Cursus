/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:38:00 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/12 17:06:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	here_document_parser_(t_dlist **new, t_dlist **tokens)
{
	t_token	*token;
	t_dlist	*temp;
	char	*value;

	token = (*tokens)->content;
	if (token->id != TD_HERE_DOCUMENT)
		return (0);
	temp = next_token_non_space(*tokens);
	value = join_words(&temp);
	if (!value)
		return (-1);
	token->value = heredoc(value);
	free(value);
	if (!token->value)
		return (-1);
	*tokens = temp;
	add_token_to_result(new, TD_HERE_DOCUMENT, token->value);
	return (1);
}

void	here_document_parser(t_dlist **tokens)
{
	t_token_parser	*parsers;

	parsers = (t_token_parser[]){here_document_parser_, common_parser, NULL};
	parser_core(tokens, parsers);
}
