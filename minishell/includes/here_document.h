/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:20:42 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/13 14:00:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOCUMENT_H
# define HERE_DOCUMENT_H

# include "minishell.h"

typedef int (*	t_token_parser)(t_dlist **new, t_dlist **tokens);

int		common_parser(t_dlist **new, t_dlist **tokens);
void	parser_core(t_dlist **tokens, t_token_parser *parsers);

char	*heredoc(char *value);
void	here_document_parser(t_dlist **tokens);

#endif
