/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:10:22 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 18:41:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_underscore_variable(t_command *command)
{
	t_dlist	*word;

	if (!command || !command->words)
		return ;
	word = ft_dlstlast(command->words);
	insert_on_hashmap("_", word->content, g_minishell.env);
}

void	process_commands(t_dlist *tokens)
{
	t_command	*command;
	int			*the_pipe;

	if (!tokens)
		return ;
	the_pipe = NULL;
	while (tokens)
	{
		null_std_fd();
		command = get_next_command(&tokens);
		if (command->op == TD_PIPE)
			operator_pipe(&the_pipe, command);
		else if (!operator_conditional(&the_pipe, command))
			break ;
		set_underscore_variable(command);
		command_free(command);
		command = NULL;
	}
	command_free(command);
	command = NULL;
	while (wait(NULL) != -1)
		;
	restore_std_fd();
}
