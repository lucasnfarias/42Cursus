/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:33:24 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 23:46:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	which_token(char *str, int *length)
{
	t_token_definition	*tokens;

	if (!str)
		return (TD_UNKNOWN);
	tokens = (t_token_definition[]){
	{.id = TD_HERE_DOCUMENT, .value = "<<", .length = 2},
	{.id = TD_AND, .value = "&&", .length = 2},
	{.id = TD_OR, .value = "||", .length = 2},
	{.id = TD_APPEND_MODE, .value = ">>", .length = 2},
	{.id = TD_PIPE, .value = "|", .length = 1},
	{.id = TD_OUTPUT, .value = ">", .length = 1},
	{.id = TD_INPUT, .value = "<", .length = 1},
	{.id = TD_DOUBLE_QUOTE, .value = "\"", .length = 1},
	{.id = TD_SINGLE_QUOTE, .value = "'", .length = 1},
	{.id = TD_SPACE, .value = " ", .length = 1},
	{.id = TD_UNKNOWN, .value = NULL, .length = 0}};
	while (tokens->id != TD_UNKNOWN
		&& ft_strncmp(tokens->value, str, tokens->length) != 0)
		tokens++;
	if (tokens->id != TD_UNKNOWN && length)
		*length = tokens->length;
	return (tokens->id);
}

static bool	quote_recognition(t_dlist **tokens, char *str, int *index)
{
	int				id;
	t_str_builder	*builder;

	id = which_token(str + *index, NULL);
	if (id != TD_SINGLE_QUOTE && id != TD_DOUBLE_QUOTE)
		return (false);
	(*index)++;
	builder = str_builder_init();
	while (str[*index] && which_token(str + *index, NULL) != id)
		if (!escaper_and_add(&builder, str, index, id))
			return (true);
	if (!str[*index])
	{
		error_handler("syntax error", "unexpected end of file", 2);
		*index = -1;
		return (true);
	}
	(*index)++;
	add_token_to_result(tokens, id, builder->str);
	str_builder_destroy(builder);
	return (true);
}

static bool	symbol_recognition(t_dlist **tokens, char *str, int *index)
{
	int	id;
	int	length;

	id = which_token(str + *index, &length);
	if (id == TD_UNKNOWN || id == TD_SINGLE_QUOTE || id == TD_DOUBLE_QUOTE)
		return (false);
	*index += length;
	while (str[*index] && id == TD_SPACE && ft_isspace(*(str + *index)))
		(*index)++;
	if (str[*index] || id != TD_SPACE)
		add_token_to_result(tokens, id, NULL);
	return (true);
}

static bool	word_recognition(t_dlist **tokens, char *str, int *index)
{
	t_str_builder	*builder;

	if (!str[*index] || which_token(str + *index, NULL) != TD_UNKNOWN)
		return (false);
	builder = str_builder_init();
	while (str[*index] && which_token(str + *index, NULL) == TD_UNKNOWN)
		if (!escaper_and_add(&builder, str, index, TD_WORD))
			return (true);
	add_token_to_result(tokens, TD_WORD, builder->str);
	str_builder_destroy(builder);
	return (true);
}

typedef bool (*	t_recognitor)(t_dlist **tokens, char *str, int *index);

t_dlist	*token_recognition(char *str)
{
	t_dlist			*tokens;
	int				index;
	int				position;
	t_recognitor	*recognitors;

	tokens = NULL;
	index = 0;
	recognitors = (t_recognitor[]){
		quote_recognition, symbol_recognition, word_recognition, NULL};
	while (str[index])
	{
		position = -1;
		while (recognitors[++position])
		{
			if (recognitors[position](&tokens, str, &index) && index != -1)
				break ;
			if (index == -1)
				return ((ft_dlstclear(&tokens, token_free), NULL));
		}
	}
	return (tokens);
}
