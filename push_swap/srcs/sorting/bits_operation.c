/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:24:37 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/01 21:39:49 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bit_on_i(int biggest_number, int i)
{
	return ((biggest_number >> i) & 1);
}

int	most_significant_bit(int biggest_number)
{
	int	i;

	i = 31;
	while (check_bit_on_i(biggest_number, i) != 1)
		i--;
	return (i);
}
