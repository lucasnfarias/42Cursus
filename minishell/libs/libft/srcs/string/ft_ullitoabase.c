/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoabase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 20:30:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:59:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_ullitoabase(unsigned long long number, char const *base)
{
	int					radix;
	int					index;
	char				*dst;
	unsigned long long	value;

	radix = ft_strlen(base);
	if (!base || !radix)
		return (0);
	value = number;
	index = ft_algs_num_base(number, radix);
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
		return (0);
	dst[0] = '-';
	dst[index] = '\0';
	while (value || index)
	{
		dst[--index] = base[value % radix];
		value /= radix;
	}
	return (dst);
}
