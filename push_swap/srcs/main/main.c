/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:28:52 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/31 22:04:04 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

// // A utility function to get maximum value in arr[]
// static int get_highest_int(t_int_node *head)
// {
// 	t_int_node *current;
// 	int max;

// 	max = head->number;
// 	current = head;
// 	while (1)
// 	{
// 		if (current->number > max)
// 			max = current->number;
// 		if (current->next == head)
// 			break;
// 		current = current->next;
// 	}
// 	return (max);
// }

// static int	list_length(t_int_node *head)
// {
// 	t_int_node	*curr;
// 	int	c;

// 	curr = head;
// 	c = 0;
// 	while (1)
// 	{
// 		c++;
// 		if (curr->next == head)
// 			break ;
// 		curr = curr->next;
// 	}
// 	return (c);
// }

// static void	sort(t_int_node *stack_a, t_int_node *stack_b, int exp, int n)
// {
// 	int	i;
// 	int	c;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		ft_putstr_fd("i: ", 1);
// 		ft_putnbr_fd(i, 1);
// 		ft_putstr_fd(" <> ", 1);
// 		ft_putstr_fd("exp: ", 1);
// 		ft_putnbr_fd(exp, 1);
// 		ft_putstr_fd("\n------\n", 1);
// 		c = 1;
// 		while (1)
// 		{
// 			ft_putstr_fd("num A: ", 1);
// 			ft_putnbr_fd(stack_a->number, 1);
// 			ft_putstr_fd("\n", 1);
// 			if ((stack_a->number / exp) % 10 == i)
// 				ps_push(&stack_a, &stack_b, "pb\n");
// 			else
// 				ps_rotate(&stack_a, "ra\n");
// 			if (c == n)
// 				break ;
// 			c++;
// 		}
// 		while (1)
// 		{
// 			if (stack_b == NULL)
// 				break;
// 			ft_putstr_fd("num B: ", 1);
// 			ft_putnbr_fd(stack_b->number, 1);
// 			ft_putstr_fd("\n", 1);
// 			ps_push(&stack_b, &stack_a, "pa\n");
// 		}
// 		i++;
// 	}
// }

// static void radixsort(t_stacks *stacks)
// {
// 	int max;
// 	int exp;
// 	int n;

// 	max = get_highest_int(stacks->a);
// 	exp = 1;
// 	n = list_length(stacks->a);
// 	while (max / exp > 0)
// 	{
// 		sort(stacks->a, stacks->b, exp, n);
// 		exp *= 10;
// 	}
// }

int main(int argc, char **argv)
{
	t_stacks *stacks;

	stacks = (t_stacks *)ft_calloc(sizeof(t_stacks), 1);
	if (argc == 1)
		exit_with_msg_error(NO_INPUT);
	validate_and_setup_stacks(stacks, argv, argc);
	// ft_putstr_fd("### Your Input:\n", 1);
	// display_stack(stacks->a, "a");
	// display_stack(stacks->b, "b");
	sort_stacks(stacks);
	// display_stack(stacks->a, "a");
	// display_stack(stacks->b, "b");
	exit(0);
}
