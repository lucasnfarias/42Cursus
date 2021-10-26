/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:26:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 16:29:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void*))
{
	if (lst && *lst)
	{
		ft_dlstclear(&((*lst)->next), del);
		ft_dlstdelone(*lst, del);
		*lst = 0;
	}
}
