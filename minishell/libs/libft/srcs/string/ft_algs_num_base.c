/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algs_num_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 09:25:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:33:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_algs_num_base(long long number, unsigned int radix)
{
	unsigned int	algs;
	long long		num;

	if (!radix)
		return (0);
	if (!number)
		return (1);
	algs = 0;
	num = number;
	if (number < 0)
		num *= 1;
	while (num)
	{
		algs++;
		num /= radix;
	}
	return (algs);
}
