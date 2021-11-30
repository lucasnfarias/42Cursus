/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:25:03 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/20 14:56:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	handle_error_message(char *error_msg, int show_args_opts)
{
	printf("%s%s%s\n", RED, error_msg, RESET_COLOR);
	if (show_args_opts)
	{
		printf("%s# ARGS%s\n", BOLD_WHITE, RESET_COLOR);
		printf("- arg 1: number_of_philosophers (1 to 200)\n");
		printf("- arg 2: time_to_die (ms)\n");
		printf("- arg 3: time_to_eat (ms)\n");
		printf("- arg 4: time_to_sleep (ms)\n");
		printf("- arg 5: number_of_times_each_philosopher_must_eat");
		printf("(optional)\n");
	}
	return (1);
}

static int	check_philos_quantity(int philos_qty)
{
	if (philos_qty > 200)
		return (handle_error_message(TOO_MANY_PHILOS, 0));
	if (philos_qty == 0)
		return (handle_error_message(ZERO_PHILOS, 0));
	if (philos_qty == 1)
	{
		printf("\033[0;33m");
		printf("Poor lonely philosopher!\n");
		printf("As he was starving to death his only thought was:\n");
		printf("'Why do I need two forks to eat spaghetti?'\n");
		printf("But he died before he could complete his line of thought.\n");
		printf("If only he had another fork...\n");
		printf("\033[0m");
		return (1);
	}
	return (0);
}

static int	check_arg_int_limit(char *arg)
{
	long long	number;

	number = ft_atoill(arg);
	if (number > INT_MAX)
		return (handle_error_message(INPUT_TOO_HIGH, 0));
	if (number < 1)
		return (handle_error_message(INPUT_TOO_LOW, 0));
	return (0);
}

static int	check_args_is_only_digits(char *arg)
{
	int	j;

	j = 0;
	if (arg[0] == '-' || arg[0] == '+')
		j++;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			return (handle_error_message(NOT_DIGIT, 1));
		j++;
	}
	return (0);
}

int	check_args_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
		return (handle_error_message(TOO_FEW_ARGS, 1));
	if (argc > 6)
		return (handle_error_message(TOO_MANY_ARGS, 1));
	if (check_philos_quantity(ft_atoi(argv[1])))
		return (1);
	while (argv[i])
	{
		if (check_args_is_only_digits(argv[i])
			|| check_arg_int_limit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
