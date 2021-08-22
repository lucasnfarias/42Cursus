/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:21:14 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/22 17:15:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_int_node **head)
{
	t_int_node	*second_node;

	if (*head == NULL || (*head)->previous == *head)
		return ;
	second_node = (*head)->next;
	(*head)->next = (*head)->next->next;
	push_stack(head, second_node->number);
	free(second_node);
}
