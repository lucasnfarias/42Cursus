/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:41:45 by lniehues          #+#    #+#             */
/*   Updated: 2021/08/30 19:55:03 by lniehues         ###   ########.fr       */
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

void	display_stack(t_int_node *head, char *stack_name)
{
	t_int_node	*current;

	current = head;
	if (head == NULL)
	{
		ft_putstr_fd(BOLD_YELLOW, 1);
		ft_putstr_fd("Stack is Empty!\n", 1);
		ft_putstr_fd(RESET_COLOR, 1);
	}
	else
	{
		ft_putstr_fd(BOLD_GREEN, 1);
		ft_putstr_fd("Stack elements: \n", 1);
		ft_putstr_fd(RESET_COLOR, 1);
		while (current->next != head)
		{
			ft_putnbr_fd(current->number, 1);
			ft_putstr_fd("\n", 1);
			current = current->next;
		}
		ft_putnbr_fd(current->number, 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("---\n", 1);
	ft_putstr_fd(stack_name, 1);
	ft_putstr_fd("\n\n", 1);
}

static int get_highest_int(t_int_node *head)
{
	t_int_node *current;
	int max;

	max = head->number;
	current = head;
	while (1)
	{
		if (current->number > max)
			max = current->number;
		if (current->next == head)
			break;
		current = current->next;
	}
	return (max);
}

void	validate_and_setup_stacks(t_stacks *stacks, char **argv, int argc)
{
	int i;

	i = 1;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->length = argc - 1;
	validate_input(argv);
	while (argv[i])
	{
		reverse_push_stack(&stacks->a, ft_atoi(argv[i]));
		i++;
	}
	stacks->biggest_number = get_highest_int(stacks->a);
}