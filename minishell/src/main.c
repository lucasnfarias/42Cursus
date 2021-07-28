/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:02:38 by lniehues          #+#    #+#             */
/*   Updated: 2021/03/13 20:02:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
# define BUFFER_SIZE 1024

void print_prompt1(void)
{
	ft_putstr_fd("\e[1;31mminiHELL$ \e[0;37m", STDERR);
}

void print_prompt2(void)
{
	ft_putstr_fd("> ", STDERR);
}

int	read_cmd(char **line)
{
	int	ret;

	ret = 0;
	*line = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line)
	{
		ft_putendl_fd("\e[1;31mminiHell$ : allocation error\e[0;37m", 1);
		exit(1);
	}
	if ((ret = read(0, *line, BUFFER_SIZE)) == -1)
	{
		if (line[BUFFER_SIZE] == 0)
			exit(0);
		else
			exit(1);
	}
	return (ret);
}

int main()
{
	char *cmd;

	cmd = NULL;
	while (1)
	{
		print_prompt1();
		read_cmd(&cmd);

		if(!cmd)
		{
		    exit(EXIT_SUCCESS);
		}
		if(cmd[0] == '\0' || ft_strncmp(cmd, "\n", ft_strlen(cmd)) == 0)
		{
		    free(cmd);
		    continue;
		}
		if(ft_strncmp(cmd, "exit\n", ft_strlen(cmd)) == 0)
		{
		  free(cmd);
			ft_putendl_fd("exit", 1);
			exit(EXIT_SUCCESS);
		}
		printf("%s", cmd);
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}
