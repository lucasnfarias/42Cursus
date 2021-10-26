/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:22:28 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 22:02:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_ullitoa(unsigned long long n)
{
	int					s;
	unsigned long long	v;
	int					index;
	char				*str;

	v = n;
	s = 0;
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
