/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsttarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:54:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/20 19:56:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

/**
 * @brief Copy the content of a dualinkedlist to an array
 *
 * @param lst A list to be converted
 * @param size The size of the list's content
 *
 * @return An array with the list's elements
 */
void	*ft_dlsttarray(t_dlist *lst, size_t size)
{
	void	*result;
	int		index;

	result = malloc(size * ft_dlstsize(lst));
	if (!result)
		return (NULL);
	index = 0;
	while (lst)
	{
		ft_memmove(result + size * index, lst->content, size);
		index++;
		lst = lst->next;
	}
	return (result);
}
