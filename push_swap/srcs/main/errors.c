/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:29:56 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:51:53 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_msg_error(char *error_code)
{
	int	fd;

	fd = open("DETAILED_ERROR_LOG.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_putendl_fd(error_code, fd);
	ft_putendl_fd("Error", 2);
	close(fd);
	exit(-1);
}

static void	is_arg_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	if (!arg[i])
		exit_with_msg_error(NOT_DIGIT);
	while (arg[i])
	{
		if (!ft_isdigit((int) arg[i]))
			exit_with_msg_error(NOT_DIGIT);
		i++;
	}
}

static void	is_valid_integer(char *number)
{
	long long int	temp;

	temp = ft_atoll(number);
	if (temp > INT_MAX)
		exit_with_msg_error(INPUT_TOO_HIGH);
	else if (temp < INT_MIN)
		exit_with_msg_error(INPUT_TOO_LOW);
}

void	validate_input(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		is_arg_digit(argv[i]);
		is_valid_integer(argv[i]);
		while (argv[j])
		{
			if (j > i)
				is_arg_digit(argv[j]);
			if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit_with_msg_error(DUPLICATE_INPUT);
			j++;
		}
		i++;
	}
}

void	*ec_calloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size, 1);
	if (ptr == NULL)
		exit_with_msg_error(MALLOC_ERROR);
	return (ptr);
}
