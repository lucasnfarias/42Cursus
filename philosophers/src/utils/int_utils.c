/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:23:55 by lniehues          #+#    #+#             */
/*   Updated: 2021/11/07 16:50:36 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
