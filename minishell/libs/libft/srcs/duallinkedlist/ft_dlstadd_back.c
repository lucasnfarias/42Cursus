/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:10:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/18 19:36:53 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_dlstlast(*lst);
		last->next = new;
		new->previous = last;
		new->next = NULL;
	}
	else
		*lst = new;
}
