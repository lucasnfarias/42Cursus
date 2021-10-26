/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/07/21 10:55:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return ((ft_lstclear(&dst, del), NULL));
		ft_lstadd_back(&dst, new);
		lst = lst->next;
	}
	return (dst);
}
