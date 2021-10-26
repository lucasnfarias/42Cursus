/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/07/21 11:02:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*dst;
	t_dlist	*new;

	if (!lst || !f || !del)
		return (NULL);
	dst = NULL;
	lst = ft_dlstlast(lst);
	while (lst)
	{
		new = ft_dlstnew(f(lst->content));
		if (!new)
			return ((ft_dlstclear(&dst, del), NULL));
		ft_dlstadd_front(&dst, new);
		lst = lst->previous;
	}
	return (dst);
}
