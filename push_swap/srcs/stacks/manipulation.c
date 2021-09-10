/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:29:05 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/01 20:29:27 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_push_stack(t_int_node **head, int new_number)
{
	t_int_node	*current;
	t_int_node	*new_node;

	new_node = (t_int_node *)ec_calloc(sizeof(t_int_node));
	new_node->number = new_number;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->previous = *head;
		new_node->next = *head;
	}
	else
	{
		current = *head;
		while (current->next != *head)
			current = current->next;
		current->next = new_node;
		new_node->previous = current;
		(*head)->previous = new_node;
		new_node->next = *head;
	}
}

void	push_stack(t_int_node **head, int new_number)
{
	t_int_node	*current;
	t_int_node	*new_node;

	new_node = (t_int_node *)ec_calloc(sizeof(t_int_node));
	new_node->number = new_number;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->previous = *head;
		new_node->next = *head;
	}
	else
	{
		current = *head;
		while (current->next != *head)
			current = current->next;
		current->next = new_node;
		new_node->previous = current;
		(*head)->previous = new_node;
		new_node->next = *head;
		*head = new_node;
	}
}

t_int_node	*pop_stack(t_int_node **head)
{
	t_int_node	*current;
	t_int_node	*temp;

	current = *head;
	if (*head == NULL)
		return (NULL);
	else if ((*head)->next == *head)
	{
		*head = NULL;
		return (current);
	}
	else
	{
		temp = *head;
		current = *head;
		while (current->next != *head)
			current = current->next;
		current->next = (*head)->next;
		(*head)->next->previous = current;
		*head = current->next;
		return (temp);
	}
}

t_int_node	*reverse_pop_stack(t_int_node **head)
{
	t_int_node	*current;
	t_int_node	*temp;

	current = *head;
	if (*head == NULL)
		return (NULL);
	else if ((*head)->next == *head)
	{
		*head = NULL;
		return (current);
	}
	else
	{
		current = *head;
		while (current->next != *head)
			current = current->next;
		temp = current;
		current->previous->next = *head;
		(*head)->previous = current->previous;
		return (temp);
	}
}
