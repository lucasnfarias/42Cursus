/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:34:53 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/24 19:53:19 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*previous_item;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		previous_item = *lst;
		*lst = previous_item->next;
		free(previous_item);
	}
	*lst = NULL;
}
