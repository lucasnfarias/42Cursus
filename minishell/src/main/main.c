/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:02:38 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/11 19:58:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void print_prompt1(void)
{
	ft_putstr_fd("\e[1;31mminiHELL$ \e[0;37m", STDIN);
}

static int cmdline_start_check(char *cmdline)
{
	if (!cmdline) // should probably handle error
	{
		exit(EXIT_SUCCESS);
	}
	if (cmdline[0] == '\0' || ft_strncmp(cmdline, "\n", ft_strlen(cmdline)) == 0) // nothing typed just continue
	{
		free(cmdline);
		return (1);
	}
	if (ft_strncmp(cmdline, "exit\n", ft_strlen(cmdline)) == 0) // exit cmdline probably need some type of errno
	{
		free(cmdline);
		ft_putendl_fd("exit", STDOUT);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int main(void)
{
	char *cmdline;

	cmdline = NULL;
	while (1)
	{
		print_prompt1();	// print cmdline prompt
		read_cmd(&cmdline); // read cmdline line
		if (cmdline_start_check(cmdline) == 1)
			continue ;
		evaluate(cmdline); // where the magic happens
		free(cmdline);
	}
	exit(EXIT_SUCCESS);
}
