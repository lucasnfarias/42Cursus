/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:10:13 by lniehues          #+#    #+#             */
/*   Updated: 2021/09/03 20:24:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	unsigned int				i;
	long int					sinal;
	unsigned long long int		base;

	i = 0;
	sinal = 1;
	base = 0;
	if (!str[i])
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		base = (base * 10) + (str[i++] - '0');
	if (base >= LONG_MAX && sinal == 1)
		return (-1);
	else if (base >= LONG_MAX && sinal == -1)
		return (0);
	return ((int)base * sinal);
}
