/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:41:45 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/04 12:38:21 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_argv_on_int_array(int *array, char **argv, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

static int	*create_indexed_positions_array(char **argv, int length)
{
	int	i;
	int	j;
	int	*original;
	int	*sorted;
	int	*indexed_array;

	original = (int *)ft_calloc(sizeof(int), length);
	sorted = (int *)ft_calloc(sizeof(int), length);
	indexed_array = (int *)ft_calloc(sizeof(int), length);
	setup_argv_on_int_array(original, argv, length);
	setup_argv_on_int_array(sorted, argv, length);
	quick_sort(sorted, 0, length - 1);
	i = 0;
	while (i < length)
	{
		j = 0;
		while (original[i] != sorted[j])
			j++;
		indexed_array[i] = j;
		i++;
	}
	free(original);
	free(sorted);
	return (indexed_array);
}

void	validate_and_setup_stacks(t_stacks *stacks, char **argv, int argc)
{
	int	i;
	int	*indexed_pos_array;

	validate_input(argv);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->length = argc - 1;
	stacks->biggest_number = INT_MIN;
	indexed_pos_array = create_indexed_positions_array(argv, stacks->length);
	i = 0;
	while (i < stacks->length)
	{
		reverse_push_stack(&stacks->a, indexed_pos_array[i]);
		if (indexed_pos_array[i] > stacks->biggest_number)
			stacks->biggest_number = indexed_pos_array[i];
		i++;
	}
	free(indexed_pos_array);
}
