/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:22:28 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:43:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_itoa(int n)
{
	int		s;
	long	v;
	int		index;
	char	*str;

	v = n;
	s = (v < 0);
	if (v < 0)
		v *= -1;
	index = ft_algs_num(v);
	if (v == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (index + s + 1));
	if (!str)
		return (0);
	str[0] = '-';
	str[index + s] = '\0';
	while (v)
	{
		str[index + s - 1] = v % 10 + '0';
		index--;
		v /= 10;
	}
	return (str);
}
