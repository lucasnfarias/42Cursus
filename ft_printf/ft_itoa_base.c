/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:24:32 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/11 16:06:49 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_abs(long long int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

size_t			ft_itoa_base_length(long number, size_t base)
{
	size_t	length;

	length = 0;
	while (1)
	{
		number /= base;
		length++;
		if (number == 0)
			break ;
	}
	return (length);
}

char			*ft_itoa_base(long num, char *base)
{
	long long			number;
	size_t				base_len;
	char				*str;
	size_t				length;

	number = (long long)num;
	base_len = ft_strlen(base);
	length = ft_itoa_base_length(num, base_len);
	if (!(str = malloc((length + 1 + (num < 0 ? 1 : 0)) * sizeof(char))))
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	str[length] = '\0';
	while (1)
	{
		str[length - 1] = base[(number % base_len)];
		number /= base_len;
		length--;
		if (number == 0)
			break ;
	}
	return (str);
}

size_t			ft_itoa_unsigned_base_len(unsigned long number, size_t base)
{
	size_t	length;

	length = 0;
	while (1)
	{
		number /= base;
		length++;
		if (number == 0)
			break ;
	}
	return (length);
}

char			*ft_itoa_unsigned_base(unsigned long num, char *base)
{
	long long			number;
	size_t				base_len;
	char				*str;
	size_t				length;

	number = num;
	base_len = ft_strlen(base);
	length = ft_itoa_unsigned_base_len(num, base_len);
	if (!(str = malloc((length + 1) * sizeof(char))))
		return (NULL);
	str[length] = '\0';
	while (1)
	{
		str[length - 1] = base[(number % base_len)];
		number /= base_len;
		length--;
		if (number == 0)
			break ;
	}
	return (str);
}
