/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:19:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:58:04 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

long long	ft_atoill(char const *str)
{
	int			s;
	long long	n;
	long long	p;

	s = 1;
	n = 0;
	p = n;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		s = 1;
		if (*str == '-')
			s = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = (n * 10) + (*(str++) - '0');
		if (p > n)
			return (!(s == -1) * -1);
		p = n;
	}
	return (s * n);
}

int	ft_atoi(char const *str)
{
	return ((int)ft_atoill(str));
}
