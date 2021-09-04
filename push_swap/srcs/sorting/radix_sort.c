/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:44:41 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/01 22:04:11 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_significant_nums_to_b(t_stacks *stacks, int bits)
{
	int	i;

	i = 0;
	while (i < stacks->length)
	{
		if (check_bit_on_i(stacks->a->number, bits) == 0)
			ps_push(&stacks->a, &stacks->b, "pb\n");
		else
			ps_rotate(&stacks->a, "ra\n");
		if (is_sorted(stacks->a))
			break ;
		i++;
	}
}

static void	push_all_back_to_stack_a(t_stacks *stacks)
{
	while (stacks->b)
		ps_push(&stacks->b, &stacks->a, "pa\n");
}

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	num_of_bits;

	i = 0;
	num_of_bits = most_significant_bit(stacks->biggest_number);
	while (i <= num_of_bits)
	{
		push_significant_nums_to_b(stacks, i);
		push_all_back_to_stack_a(stacks);
		i++;
	}
}
