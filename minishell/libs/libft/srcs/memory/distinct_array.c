/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinct_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:22:56 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/17 20:24:26 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "sorting.h"

static int	count_distinct_elements(
	const void *elements,
	size_t size,
	t_comparator equal,
	int length)
{
	int	index;
	int	distincts;

	index = -1;
	distincts = 1;
	while (++index < length - 1)
		if (!equal(elements + size * index, elements + size * (index + 1)))
			distincts++;
	return (distincts);
}

/**
 * @brief Return an array of distincts elements
 *
 * @example [1, 2, 2, 4, 5, 5] -> [4, 1, 2, 4, 5]
 * @example ['a', 'a', 'b', 'c', 'c'] -> [3, 'a', 'b', 'c']
 *
 * @param elements An ordered list of elements
 * @param size The size of an element
 * @param comparator A function to compare if two elements are equal
 * @param length The number of elements
 *
 * @return An array with the quantity and the distincts elements
 */
void	*distinct_array(
	const void *e,
	size_t s,
	t_comparator eq,
	int l)
{
	int				distincts;
	unsigned char	*result;
	int				index;

	if (!e || !s || !eq || l <= 0)
		return (NULL);
	distincts = count_distinct_elements(
			(const unsigned char*)e, s, eq, l);
	result = malloc(s * distincts + sizeof(int));
	if (!result)
		return (NULL);
	*(int *)result = distincts;
	ft_memmove(result + s * (distincts - 1) + sizeof(int), e + s * (l - 1), s);
	index = 0;
	l = 0;
	while (index < distincts - 1)
	{
		if (!eq(e + s * l, e + s * (l + 1)))
			ft_memmove(result + sizeof(int) + s * index++, e + s * l, s);
		l++;
	}
	return (result);
}
