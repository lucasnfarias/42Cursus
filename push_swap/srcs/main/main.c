/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:28:52 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/18 21:35:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_args(char **argv)
{
	int	i;

	i = 1;
	validate_input(argv);
	ft_putstr_fd("### Your Input:\n", 1);
	while (argv[i])
	{
		ft_putnbr_fd(ft_atoi(argv[i]), 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_with_msg_error(NO_INPUT);
	if (argc > 1 && argv[1])
		process_args(argv);
	return (0);
}
