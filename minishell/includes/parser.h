/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:25:50 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/09 14:19:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

char	*expand_all_variables(char *str);
char	*expand_and_join_words(t_dlist **tokens);

char	*join_words(t_dlist **tokens);
bool	word_parser(t_dlist **new, t_dlist **tokens);

void	show_tokens(t_dlist **ptr_tokens);

#endif
