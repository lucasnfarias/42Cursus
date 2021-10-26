/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:17:10 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/20 08:59:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	EXPECTED BEHAVIOR:
*
*	- no args -> exits -> $? == {last_exit_status}
*	- one num arg -> exits -> $? == {arg_num}
*	- more than one arg -> doesn't exits -> $? == 1
*	- one or more non-num args -> exits -> $? == 2
*/

void	exit_minishell(void)
{
	rl_clear_history();
	free_hashmap_bucket(g_minishell.local_var);
	free_hashmap_bucket(g_minishell.env);
	close_std_fd();
	exit(g_minishell.error_status);
}

static int	get_argc(char **argv)
{
	int	i;

	i = 0;
	while (*(++argv))
		i++;
	return (i);
}

static bool	arg_only_digit(char *arg)
{
	int		i;
	bool	valid;

	i = 0;
	valid = false;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit((int)arg[i]))
			return (false);
		i++;
		valid = true;
	}
	return (valid);
}

static void	validate_first_arg(char *arg)
{
	if (!arg)
		return ;
	if (arg_only_digit(arg))
	{
		g_minishell.error_status = ft_atoi(arg);
		return ;
	}
	error_handler_arg("exit", arg, NUM_ARG_REQUIRED, 2);
	exit_minishell();
}

void	exit_builtin(char **argv)
{
	int	argc;

	if (isatty(STDOUT_FILENO))
		ft_putendl_fd("exit", 1);
	argc = get_argc(argv);
	validate_first_arg(argv[1]);
	if (argc > 1)
	{
		error_handler("exit", TOO_MANY_ARGS, 1);
		return ;
	}
	exit_minishell();
}
