/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:49:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/17 16:52:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

/**
 * \brief Swap two elements
 *
 * @param a First element
 * @param b Second element
 *
 * @return A pointer for the first element of NULL when it fails
 */
void	*generic_swap(void *a, void *b, size_t size)
{
	void	*c;

	if (!a || !b || !size)
		return (NULL);
	c = malloc(size);
	if (!c)
		return (NULL);
	ft_memmove(c, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, c, size);
	free(c);
	return (NULL);
}
