/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:28:04 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/16 12:58:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

typedef struct s_command
{
	t_dlist	*words;
	t_dlist	*variables;
	t_dlist	*redirects;
	int		op;
}				t_command;

typedef bool (*	t_command_handler) (t_command *command, t_dlist **tokens);

t_command		*command_init(void);
void			command_free(t_command *command);

pid_t			configure_redirect(t_command *command);

pid_t			execute_program(t_command *command);

pid_t			operator_pipe(int **input, t_command *command);
bool			operator_conditional(int **input, t_command *command);

t_command		*get_next_command(t_dlist **tokens);

void			command_show(t_command *command);

void			process_commands(t_dlist *tokens);

#endif
