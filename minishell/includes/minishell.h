/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:27:00 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/19 07:43:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./../libs/libft/srcs/includes/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

# include "hashmap.h"
# include "builtins.h"
# include "env.h"
# include "here_document.h"
# include "parser.h"
# include "signals.h"
# include "styles.h"
# include "input.h"
# include "tokens.h"
# include "util.h"
# include "commands.h"

typedef struct s_minishell
{
	t_hashmap	*env;
	t_hashmap	*local_var;
	int			error_status;
	pid_t		fd_in;
	pid_t		fd_out;
	pid_t		fd_err;
	pid_t		fd_null;
	int			heredoc_line;
	int			general_line;
	bool		interactive;
	char		*pwd;
}				t_minishell;

/* GLOBAL VARIABLE */
t_minishell	g_minishell;

#endif
