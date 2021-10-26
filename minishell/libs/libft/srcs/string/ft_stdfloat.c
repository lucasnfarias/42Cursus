/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:45:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 00:20:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "internal/math.h"

int	ft_stdfloat_exp(double number)
{
	double	value;
	int		index;

	value = number;
	if (number < 0)
		value *= -1;
	index = 0;
	if (value == 0)
		return (index);
	while (value >= 10)
	{
		value /= 10;
		index++;
	}
	while (value < 1)
	{
		value *= 10;
		index--;
	}
	return (index);
}

char	*ft_stdfloat_num(long double number, int precision)
{
	int			exp;
	long double	value;
	char		*result;

	exp = ft_stdfloat_exp(number) * -1;
	value = number * ft_pow(10, exp);
	result = ft_ftoa(value, precision);
	return (result);
}

char	*ft_stdfloat_limits(long double number)
{
	if (number == (-1. / 0.))
		return (ft_strdup("-inf"));
	if (number == (1. / 0.))
		return (ft_strdup("inf"));
	return (NULL);
}
