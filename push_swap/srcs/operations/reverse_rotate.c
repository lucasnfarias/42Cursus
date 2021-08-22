/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:21:14 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/22 17:50:15 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse_rotate(t_int_node **head)
{
	t_int_node	*last_node;

	if (*head == NULL || (*head)->previous == *head)
		return ;
	last_node = reverse_pop_stack(head);
	if (last_node)
	{
		push_stack(head, last_node->number);
		free(last_node);
	}
}
