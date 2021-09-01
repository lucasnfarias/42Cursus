/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:41:45 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/01 20:36:28 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_phrase(char *phrase, char *color, int fd)
{
	if (color)
	{
		ft_putstr_fd(color, fd);
		ft_putstr_fd(phrase, fd);
		ft_putstr_fd(RESET_COLOR, fd);
	}
	else
		ft_putstr_fd(phrase, fd);
}

void	display_stack(t_int_node *head, char *stack_name)
{
	t_int_node	*current;

	current = head;
	if (head == NULL)
		print_phrase("Stack is Empty!\n", BOLD_YELLOW, 1);
	else
	{
		print_phrase("Stack elements: \n", BOLD_GREEN, 1);
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

static int	get_highest_int(t_int_node *head)
{
	t_int_node	*current;
	int			max;

	max = head->number;
	current = head;
	while (1)
	{
		if (current->number > max)
			max = current->number;
		if (current->next == head)
			break ;
		current = current->next;
	}
	return (max);
}

void	validate_and_setup_stacks(t_stacks *stacks, char **argv, int argc)
{
	int	i;

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
