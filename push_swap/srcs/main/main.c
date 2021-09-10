/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:28:52 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:57:50 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)ft_calloc(sizeof(t_stacks), 1);
	if (argc == 1)
		exit(0);
	validate_and_setup_stacks(stacks, argv, argc);
	sort_stacks(stacks);
	exit(0);
}
