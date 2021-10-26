/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:21:03 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/20 19:34:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

void	ft_dlstdelone(t_dlist *lst, void (*del)(void*))
{
	if (del)
		del(lst->content);
	free(lst);
}
