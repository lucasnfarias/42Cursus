/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:21:14 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/26 21:32:47 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_int_node **head, char *op_name)
{
	t_int_node	*first_node;

	if (*head == NULL || (*head)->previous == *head)
		return ;
	first_node = pop_stack(head);
	if (first_node)
	{
		reverse_push_stack(head, first_node->number);
		free(first_node);
	}
	ft_putstr_fd(op_name, 1);
}
