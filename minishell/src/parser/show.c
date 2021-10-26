/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:43:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/09 18:10:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_tokens(t_dlist **ptr_tokens)
{
	t_dlist		*tokens;
	t_token		*token;
	char		*names[15];

	tokens = *ptr_tokens;
	names[TD_WORD] = "WORD";
	names[TD_HERE_DOCUMENT] = "HERE_DOCUMENT";
	names[TD_AND] = "AND";
	names[TD_OR] = "OR";
	names[TD_APPEND_MODE] = "APPEND_MODE";
	names[TD_SPACE] = "SPACE";
	names[TD_SINGLE_QUOTE] = "SINGLE_QUOTE";
	names[TD_DOUBLE_QUOTE] = "DOUBLE_QUOTE";
	names[TD_PIPE] = "PIPE";
	names[TD_INPUT] = "INPUT";
	names[TD_OUTPUT] = "OUTPUT";
	names[TD_VARIABLE] = "VARIABLE";
	while (tokens)
	{
		token = (t_token *)tokens->content;
		printf("<%s, %s>\n", names[token->id], token->value);
		tokens = tokens->next;
	}
}
