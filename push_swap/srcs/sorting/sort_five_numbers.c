/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:56:54 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/31 22:03:36 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_smallest_to_stack_b(t_stacks *stacks, int index, int is_first)
{
	if (index == 1)
		ps_swap(&stacks->a, "sa\n");
	else if (index == 2)
	{
		ps_rotate(&stacks->a, "ra\n");
		ps_swap(&stacks->a, "sa\n");
	}
	else if ((is_first && index == 3))
	{
		ps_reverse_rotate(&stacks->a, "rra\n");
		ps_reverse_rotate(&stacks->a, "rra\n");
	}
	else if ((is_first && index == 4) || index == 3)
		ps_reverse_rotate(&stacks->a, "rra\n");
	ps_push(&stacks->a, &stacks->b, "pb\n");
}

static int	find_smallest_int(t_stacks *stacks)
{
	int			smallest;
	t_int_node	*current;
	t_int_node	*head;

	smallest = stacks->a->number;
	current = stacks->a;
	head = stacks->a;
	while (current->next != head)
	{
		if (current->number < smallest)
			smallest = current->number;
		current = current->next;
	}
	if (current->number < smallest)
		smallest = current->number;
	return (smallest);
}

static int	find_smallest_int_index(t_stacks *stacks)
{
	int			i;
	int			smallest;
	t_int_node	*current;
	t_int_node	*head;

	i = 0;
	smallest = find_smallest_int(stacks);
	current = stacks->a;
	head = stacks->a;
	while (current->next != head)
	{
		if (current->number == smallest)
			break ;
		i++;
		current = current->next;
	}
	return (i);
}

void	sort_five_numbers(t_stacks *stacks)
{
	int	index;

	index = find_smallest_int_index(stacks);
	push_smallest_to_stack_b(stacks, index, 1);
	index = find_smallest_int_index(stacks);
	push_smallest_to_stack_b(stacks, index, 0);
	sort_three_numbers(stacks);
	ps_push(&stacks->b, &stacks->a, "pa\n");
	ps_push(&stacks->b, &stacks->a, "pa\n");
}
