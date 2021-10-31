/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:26:24 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/31 19:28:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned int	get_num_len(unsigned int n, int num)
{
	unsigned int	size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	if (num < 0)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char				*str;
	unsigned int		len;
	unsigned int		num;
	unsigned int		i;

	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	len = get_num_len(num, n);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	if (n < 0)
		str[i] = '-';
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