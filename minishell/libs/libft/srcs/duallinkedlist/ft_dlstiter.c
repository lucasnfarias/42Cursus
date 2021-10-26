/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:53:30 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 16:29:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(void *))
{
	if (lst)
	{
		f(lst->content);
		ft_dlstiter(lst->next, f);
	}
}
