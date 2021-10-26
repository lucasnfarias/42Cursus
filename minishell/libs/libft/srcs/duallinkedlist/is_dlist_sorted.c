/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dlist_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:00:21 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/18 21:20:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

/**
 * @brief Verify if a list is sorted
 *
 * @param list The list to be verified
 * @param comparator A function that return true when the elemens are sorted
 *
 * @return true when all elements are sorted
 */
bool	is_dlist_sorted(t_dlist *list, t_comparator comparator)
{
	if (!list)
		return (false);
	while (list->next)
	{
		if (!comparator(list->content, list->next->content))
			return (false);
		list = list->next;
	}
	return (true);
}
