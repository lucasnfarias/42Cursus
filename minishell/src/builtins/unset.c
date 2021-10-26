/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:19:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/18 23:03:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_alnum(char *value)
{
	if (!value || !*value || (!ft_isalpha(*value) && *value != '_'))
		return (false);
	while (*value)
	{
		if (!ft_isalnum(*value) && *value != '_')
			return (false);
		value++;
	}
	return (true);
}

static void	error_variable(char *var)
{
	char	*line;

	g_minishell.error_status = 1;
	if (g_minishell.interactive)
	{
		ft_putstrs_fd(
			(char *[]){"minishell: unset: `", var,
			"': not a valid identifier\n", NULL},
			STDERR_FILENO);
	}
	else
	{
		line = ft_itoa(g_minishell.general_line);
		ft_putstrs_fd(
			(char *[]){"minishell: line ", line, ": unset: `", var,
			"': not a valid identifier\n", NULL},
			STDERR_FILENO);
		free(line);
	}
}

void	unset_builtin(char **args)
{
	size_t	index;

	if (!args[1])
		return ;
	index = 0;
	while (args[++index])
	{
		if (!is_alnum(args[index]))
		{
			error_variable(args[index]);
			return ;
		}
		remove_from_hashmap(g_minishell.env, args[index]);
		remove_from_hashmap(g_minishell.local_var, args[index]);
	}
	g_minishell.error_status = 0;
}
