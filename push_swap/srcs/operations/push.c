/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:21:14 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/27 20:54:05 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_int_node **stack_from, t_int_node **stack_to, char *op_name)
{
	t_int_node	*first_node;

	if (*stack_from == NULL)
		return ;
	first_node = pop_stack(stack_from);
	if (first_node)
	{
		push_stack(stack_to, first_node->number);
		free(first_node);
	}
	ft_putstr_fd(op_name, 1);
}
