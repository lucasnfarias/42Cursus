/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_escaper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:24:10 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 23:56:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	escaper_and_add(
	t_str_builder **builder, char *str, int *index, int token)
{
	t_token	*t;

	if (!builder || !str || !index)
		return (false);
	if (str[*index] == '\\' && str[*index + 1] == '\0')
	{
		t = token_init(TD_ESCAPE, NULL);
		syntax_error(t);
		token_free(t);
		*index = -1;
		return (false);
	}
	if ((ft_strchr("`\"\\", str[*index + 1]) || token != TD_DOUBLE_QUOTE)
		&& str[*index] == '\\' && token != TD_SINGLE_QUOTE
		&& str[*index + 1] != '$')
		(*index)++;
	str_builder_add_char(*builder, str[(*index)++]);
	return (true);
}
