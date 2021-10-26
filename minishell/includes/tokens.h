/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:02:57 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/18 23:45:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

# define TD_UNKNOWN		   -1
# define TD_WORD			0
# define TD_HERE_DOCUMENT	1
# define TD_AND				2
# define TD_OR				3
# define TD_APPEND_MODE		4
# define TD_SPACE			5
# define TD_SINGLE_QUOTE	6
# define TD_DOUBLE_QUOTE	7
# define TD_PIPE			8
# define TD_INPUT			9
# define TD_OUTPUT			10
# define TD_VARIABLE		11
# define TD_NEWLINE			12
# define TD_ESCAPE			13

typedef struct s_token_definition
{
	int			id;
	char		*value;
	size_t		length;
}			t_token_definition;

typedef struct s_token
{
	int		id;
	char	*value;
}			t_token;

t_token		*token_init(int id, char *str_to_copy);
void		token_free(void *token);
bool		escaper_and_add(
				t_str_builder **builder,
				char *str,
				int *index,
				int token);
t_dlist		*add_token_to_result(t_dlist **tokens, int id, char *str);
t_dlist		*next_token_non_space(t_dlist *tokens);
t_dlist		*previous_token(t_dlist *tokens);
t_dlist		*token_recognition(char *str);
bool		tokens_validator(t_dlist *tokens);

#endif
