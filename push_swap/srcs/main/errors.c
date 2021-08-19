/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:29:56 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/18 21:33:51 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_msg_error(char *error_code)
{
	ft_putstr_fd(BOLD_RED, 1);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(error_code, 2);
	ft_putstr_fd(RESET_COLOR, 1);
	exit(errno);
}

static void	is_arg_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit((int) arg[i]))
			exit_with_msg_error(NOT_DIGIT);
		i++;
	}
}

void	validate_input(char **argv)
{
	int	i;
	int	j;
	int	int_max_length;

	int_max_length = ft_strlen(ft_itoa(INT_MIN));
	i = 1;
	while (argv[i])
	{
		j = 1;
		is_arg_digit(argv[i]);
		while (argv[j])
		{
			if (i != j && ft_strncmp(argv[i], argv[j], int_max_length) == 0)
				exit_with_msg_error(DUPLICATE_INPUT);
			j++;
		}
		i++;
	}
}
