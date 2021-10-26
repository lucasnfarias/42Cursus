/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:27:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/09/25 10:30:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static void	ft_strtol_base(char **nptr, int *base)
{
	if ((*base == 0 || *base == 16) && **nptr == '0'
		&& (*(*nptr + 1) == 'x' || *(*nptr + 1) == 'X'))
	{
		*nptr += 2;
		*base = 16;
	}
	if (*base == 0 && **nptr == '0')
		*base = 8;
	if (*base == 0)
		*base = 10;
}

static long	ft_strtol_core(char **nptr, int *base, bool negative)
{
	int		current;
	long	result;
	long	limit;
	long	max;

	max = LONG_MAX;
	if (negative)
		max = -(unsigned long)LONG_MIN;
	limit = max % *base;
	max /= *base;
	while (**nptr)
	{
		if (ft_isdigit(**nptr))
			current = **nptr - '0';
		else
			current = ft_toupper(**nptr) - 'A' + 10;
		if (current >= *base)
			break ;
		if ((result == max && current > limit) || *base == -1)
			*base = -1;
		else
			result = (result * *base) + current;
		(*nptr)++;
	}
	return (result);
}

long	ft_strtol(char *nptr, char **endptr, int base)
{
	bool	negative;
	long	result;

	while (ft_isspace(*nptr))
		nptr++;
	negative = false;
	if (*nptr == '-' || *nptr == '+')
	{
		negative = *nptr == '-';
		nptr++;
	}
	ft_strtol_base(&nptr, &base);
	result = ft_strtol_core(&nptr, &base, negative);
	if (base == -1)
	{
		errno = ERANGE;
		result = LONG_MAX;
		if (negative)
			result = LONG_MIN;
	}
	else if (negative)
		result = -result;
	if (endptr)
		*endptr = nptr;
	return (result);
}
