/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:28:52 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/22 17:50:58 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static void	init_stack(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

static void	process_args(t_stacks *stacks, char **argv)
{
	int	i;

	i = 1;
	validate_input(argv);
	ft_putstr_fd("### Your Input:\n", 1);
	while (argv[i])
	{
		reverse_push_stack(&stacks->a, ft_atoi(argv[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)ft_calloc(sizeof(t_stacks), 1);
	init_stack(stacks);
	if (argc == 1)
		exit_with_msg_error(NO_INPUT);
	process_args(stacks, argv);
	display_stack(stacks->a, "a");
	display_stack(stacks->b, "b");
	ft_putstr_fd("sa pb pb\n", 1);
	ps_swap(&stacks->a);
	ps_push(&stacks->a, &stacks->b);
	ps_push(&stacks->a, &stacks->b);
	display_stack(stacks->a, "a");
	display_stack(stacks->b, "b");
	ft_putstr_fd("ra ra\n", 1);
	ps_rotate(&stacks->a);
	ps_rotate(&stacks->a);
	display_stack(stacks->a, "a");
	display_stack(stacks->b, "b");
	ft_putstr_fd("rra\n", 1);
	ps_reverse_rotate(&stacks->a);
	display_stack(stacks->a, "a");
	display_stack(stacks->b, "b");
	exit(0);
}
