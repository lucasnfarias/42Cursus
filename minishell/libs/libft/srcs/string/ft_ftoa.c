/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:32:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 00:20:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "internal/math.h"

long long int	ft_ftoa_pvalue(double n, int p, int *s, int *l)
{
	long long int	value;

	value = n * ft_pow(10, p + 1);
	if (value % 10 == 5 || value % 10 == -5)
		value += (value / 10) % 2 * 10;
	else if (value % 10 > 5)
		value += 10;
	else if (value % 10 < -5)
		value -= 10;
	value /= 10;
	*s = ft_hexfloat_signal(n);
	*l = ft_algs_num(value * ft_pow(10, p * -1)) + (p != 0) + p;
	return (value);
}

char	*ft_ftoa_num(long double number, int precision)
{
	int				signal;
	long long int	value;
	int				length;
	char			*temp;

	if (precision < 0)
		precision = 0;
	value = ft_abs(ft_ftoa_pvalue(number, precision, &signal, &length));
	temp = malloc(sizeof(char) * (signal + length + 1));
	if (!temp)
		return (NULL);
	temp[0] = '-';
	temp[signal + length] = '\0';
	while (length--)
	{
		temp[signal + length] = value % 10 + '0';
		value /= 10;
		if (--precision == 0)
			temp[signal + --length] = '.';
	}
	return (temp);
}

char	*ft_ftoa(long double number, int precision)
{
	if (number == 0. / 0.)
		return (ft_strdup("nan"));
	if (number == -1. / 0.)
		return (ft_strdup("-inf"));
	if (number == 1. / 0.)
		return (ft_strdup("inf"));
	return (ft_ftoa_num(number, precision));
}
