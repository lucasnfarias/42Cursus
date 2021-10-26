/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:59:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:39:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_nitoa(char size, int value)
{
	int		length;
	char	*result;

	length = ft_algs_num(value);
	if (length < size)
		length = size;
	result = malloc(sizeof(char) * (length + 2));
	if (!result)
		return (NULL);
	result[length + 1] = '\0';
	result[0] = '+';
	if (value < 0)
		result[0] = '-';
	if (value < 0)
		value *= -1;
	while (length)
	{
		result[length--] = value % 10 + '0';
		value /= 10;
	}
	return (result);
}
