/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:07:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 16:29:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

t_dlist	*ft_dlstfirst(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}
