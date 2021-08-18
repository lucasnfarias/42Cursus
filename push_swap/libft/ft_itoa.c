/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:24:20 by lniehues          #+#    #+#             */
/*   Updated: 2020/01/23 19:49:22 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	get_num_len(unsigned int n)
{
	unsigned int	size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	char				*str;
	unsigned int		len;
	unsigned int		num;
	unsigned int		i;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	len = get_num_len(num);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0 && (str[i] = '-'))
		len++;
	i = len - 1;
	while (num >= 10)
	{
		str[i--] = (char)(num % 10 + 48);
		num /= 10;
	}
	str[i] = (char)(num % 10 + 48);
	str[len] = '\0';
	return (str);
}
