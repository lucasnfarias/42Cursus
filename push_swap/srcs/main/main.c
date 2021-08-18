/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:28:52 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/17 22:00:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
	{
		if (!ft_strncmp(argv[1], "NO_INPUT", 20))
			exit_with_msg_error(NO_INPUT);
		else if (!ft_strncmp(argv[1], "NOT_DIGIT", 20))
			exit_with_msg_error(NOT_DIGIT);
		if (!ft_strncmp(argv[1], "INPUT_TOO_HIGH", 20))
			exit_with_msg_error(INPUT_TOO_HIGH);
		if (!ft_strncmp(argv[1], "INPUT_TOO_LOW", 20))
			exit_with_msg_error(INPUT_TOO_LOW);
	}
	return (0);
}
