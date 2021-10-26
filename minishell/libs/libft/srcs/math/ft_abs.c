/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:49 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 00:06:53 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/math.h"

long	ft_abs(long number)
{
	long long int	temp;

	if (number < 0)
		temp = number * -1;
	else
		temp = number;
	return (temp);
}
