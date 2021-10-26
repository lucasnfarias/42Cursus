/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:59:31 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:45:23 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char const	*ps1;
	unsigned char const	*ps2;

	ps1 = (unsigned char const *)s1;
	ps2 = (unsigned char const *)s2;
	while (*s1 || *s2)
	{
		if (*ps1 != *ps2 || !*ps1 || !*ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
	}
	return (0);
}
