/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:39:59 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/20 21:47:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

t_dlist	*ft_dlstpop(t_dlist **lst, t_dlist *element)
{
	t_dlist	*previous;
	t_dlist	*next;

	if (!lst || !element)
		return (NULL);
	previous = element->previous;
	next = element->next;
	if (previous)
		previous->next = next;
	if (next)
		next->previous = previous;
	if (*lst == element)
		*lst = next;
	element->previous = NULL;
	element->next = NULL;
	return (element);
}
