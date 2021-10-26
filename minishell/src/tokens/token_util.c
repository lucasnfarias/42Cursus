/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:33:24 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/09 17:54:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_init(int id, char *str_to_copy)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->id = id;
	token->value = NULL;
	if (str_to_copy)
		token->value = ft_strdup(str_to_copy);
	if (str_to_copy && !token->value)
		return ((free(token), NULL));
	return (token);
}

void	token_free(void *token)
{
	t_token	*t;

	if (!token)
		return ;
	t = token;
	if (t->value)
		free(t->value);
	free(t);
}

t_dlist	*add_token_to_result(
	t_dlist **tokens,
	int id,
	char *str)
{
	t_token	*token;
	t_dlist	*node;

	if (id == TD_WORD && (!str || !ft_strlen(str)))
		return (NULL);
	token = token_init(id, str);
	if (!token)
		return (NULL);
	node = ft_dlstnew(token);
	if (!node)
		return (NULL);
	ft_dlstadd_back(tokens, node);
	return (node);
}

t_dlist	*next_token_non_space(t_dlist *tokens)
{
	t_token	*token;

	if (!tokens || !tokens->next)
		return (NULL);
	tokens = tokens->next;
	token = tokens->content;
	if (token->id == TD_SPACE)
		return (tokens->next);
	return (tokens);
}

t_dlist	*previous_token(t_dlist *tokens)
{
	t_token	*token;

	if (!tokens || !tokens->previous)
		return (NULL);
	tokens = tokens->previous;
	token = tokens->content;
	if (token->id == TD_SPACE)
		return (tokens->previous);
	return (tokens);
}
