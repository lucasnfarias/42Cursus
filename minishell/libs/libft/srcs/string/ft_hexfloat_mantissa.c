/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexfloat_mantissa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:43:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 22:29:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static unsigned char	*ft_hexfloat_mantissa_m(
	unsigned long long int n,
	int p)
{
	unsigned char	*m;
	int				index;

	index = 13 + 2;
	if (p > 13)
		index = p + 2;
	m = ft_calloc(index, sizeof(unsigned char));
	if (!m)
		return (NULL);
	index = -1;
	m[0] = 1;
	while (index++ < 12)
		m[13 - index] = (n >> (4 * index)) & 0xf;
	if (m[p + 1] >= 8)
		m[p]++;
	return (m);
}

static char	*ft_hexfloat_mantissa_p(
	unsigned char *m,
	int p)
{
	int		index;
	char	*r;

	index = 2;
	if (p > 0)
		index = p + 3;
	r = ft_calloc(index, sizeof(unsigned char));
	if (!r)
		return (NULL);
	r[0] = "0123456789abcdef"[m[0]];
	r[1] = '\0';
	if (p > 0)
		r[1] = '.';
	index = p + 1;
	while (--index)
		r[index + 1] = "0123456789abcdef"[m[index]];
	return (r);
}

static char	*ft_hexfloat_mantissa_(unsigned long long int n, int p)
{
	unsigned char	*m;
	char			*r;

	m = ft_hexfloat_mantissa_m(n, p);
	if (!m)
		return (NULL);
	r = ft_hexfloat_mantissa_p(m, p);
	free(m);
	return (r);
}

char	*ft_hexfloat_mantissa(double number, int precision)
{
	unsigned long long int	*n;
	unsigned long long int	mantissa;

	n = (unsigned long long int *)&number;
	mantissa = *n & 0x000FFFFFFFFFFFFF;
	if (number == 0. / 0.)
		return (ft_strdup("nan"));
	if (number == -1. / 0.)
		return (ft_strdup("-inf"));
	if (number == 1. / 0.)
		return (ft_strdup("inf"));
	return (ft_hexfloat_mantissa_(mantissa, precision));
}
