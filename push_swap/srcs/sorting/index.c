/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:41:56 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/01 21:47:29 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_int_node *head)
{
	t_int_node	*current;

	current = head;
	if (!current)
		return (0);
	while (current->next != head)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	sort_two_numbers(t_stacks *stacks)
{
	ps_rotate(&stacks->a, "ra\n");
}

void	sort_stacks(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	if (stacks->length == 2)
		sort_two_numbers(stacks);
	else if (stacks->length == 3)
		sort_three_numbers(stacks);
	else if (stacks->length == 5)
		sort_five_numbers(stacks);
	else
		radix_sort(stacks);
}
