/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:30:38 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 21:50:31 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_variable(char *keyvalue)
{
	char		**parts;
	char		*value;
	t_hashmap	*ht;

	if (!keyvalue)
		return ;
	parts = ft_split(keyvalue, '=');
	if (!parts)
		exit_minishell();
	ht = g_minishell.env;
	value = find_hashmap_value(ht, parts[0]);
	if (!value)
	{
		ht = g_minishell.local_var;
		value = find_hashmap_value(ht, parts[0]);
	}
	if (!value || (ft_strchr(keyvalue, '=') && value))
		insert_on_hashmap(parts[0], parts[1], ht);
	free(value);
	free_str_array(parts);
}
