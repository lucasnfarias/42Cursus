/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeatchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:08:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:38:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_repeatchr(unsigned char c, int times)
{
	unsigned char	*result;

	if (times < 0)
		times = 0;
	result = ft_calloc(times + 1, sizeof(unsigned char));
	ft_memset(result, c, times);
	return ((char *)result);
}
