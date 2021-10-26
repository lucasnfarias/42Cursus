/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:43:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 22:27:14 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_hexfloat_signal(double number)
{
	unsigned long long	*n;

	n = (unsigned long long *)&number;
	return (*n >> 63 & 1);
}

int	ft_hexfloat_precision(double number)
{
	unsigned long long int	*a;
	unsigned long long int	b;
	int						index;

	a = (unsigned long long int *)&number;
	b = *a & 0x000fffffffffffff;
	index = -1;
	while (index++ < 13 - 1)
	{
		if ((b >> (4 * index)) & 0xf)
			break ;
	}
	return (13 - index);
}

int	ft_hexfloat_exp(double number)
{
	unsigned long long	*n;
	int					exp;

	n = (unsigned long long *)&number;
	exp = (long)(*n >> 52 & 0x7ff) - 1023;
	return (exp);
}
