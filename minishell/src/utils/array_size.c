/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:23:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/13 14:01:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	array_size(void	**arr)
{
	size_t	index;

	if (!arr)
		return (0);
	index = 0;
	while (arr[index])
		index++;
	return (index);
}
