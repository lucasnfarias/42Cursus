/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:48:47 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/17 20:29:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "libft.h"

void	*heapsort(
			void *elements,
			size_t size,
			t_comparator comparator,
			int length);

#endif
