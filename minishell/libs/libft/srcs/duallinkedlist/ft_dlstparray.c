/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstparray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:55:34 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/20 21:00:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

/**
 * @brief Copy the content of an array to a dualinkedlist
 *
 * @param arr Array with the elements to the list
 * @param size The size of an element
 * @param length Quantity of elements
 *
 * @return A list and each node is an element of the array
 */
t_dlist	*ft_dlstparray(void	*arr, size_t size, int length)
{
	t_dlist	*lst;
	void	*element;
	t_dlist	*node;

	lst = NULL;
	while (length--)
	{
		element = malloc(size);
		if (!element)
			return ((ft_dlstclear(&lst, free), NULL));
		ft_memmove(element, arr + size * length, size);
		node = ft_dlstnew(element);
		if (!node)
			return ((ft_dlstclear(&lst, free), NULL));
		ft_dlstadd_front(&lst, node);
	}
	return (lst);
}
