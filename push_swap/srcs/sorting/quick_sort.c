/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:41:07 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 21:43:00 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *array, int i, int j)
{
	int	temp;

	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}

static int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
		}
		j++;
	}
	swap(array, i + 1, end);
	return (i + 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	partition_index;

	partition_index = 0;
	if (start < end)
	{
		partition_index = partition(array, start, end);
		quick_sort(array, start, partition_index - 1);
		quick_sort(array, partition_index + 1, end);
	}
}
