/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:12:31 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:00:26 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_specifier(t_print_op *operation)
{
	const char	*format;

	format = operation->format;
	operation->specifier = *format;
	operation->format++;
	if (!ft_strchr("iduoxXfFeEgGaAcspn%%", *format))
		return (1);
	if (ft_isupper(operation->specifier))
		operation->upper = true;
	return (0);
}

int	parse_length(t_print_op *operation)
{
	int		index;
	char	**lengths;

	index = 1;
	lengths = (char *[9]){"hh", "h", "ll", "l", "j", "z", "t", "L", NULL};
	while (*lengths)
	{
		if (!ft_strncmp(*lengths, operation->format, ft_strlen(*lengths)))
		{
			operation->length = index;
			operation->format += ft_strlen(*lengths);
			return (0);
		}
		index++;
		lengths++;
	}
	return (0);
}

int	parse_precision(t_print_op *operation)
{
	const char	*format;

	format = operation->format;
	if (*format != '.')
		return (0);
	format++;
	if (ft_isdigit(*format))
		operation->precision = ft_atoi(format);
	if (*format == '*')
		operation->precision = va_arg(*operation->arguments, int);
	while (ft_isdigit(*format) || *format == '*')
		format++;
	operation->format = format;
	if (operation->precision >= 0)
		operation->config |= HAS_PRECISION;
	return (0);
}

int	parse_width(t_print_op *operation)
{
	const char	*format;

	format = operation->format;
	if (*format != '*' && !ft_isdigit(*format))
		return (0);
	operation->config |= HAS_WIDTH;
	operation->width = ft_atoi(format);
	if (*format == '*')
		operation->width = va_arg(*operation->arguments, int);
	while (ft_isdigit(*format) || *format == '*')
		format++;
	operation->format = format;
	if (operation->width < 0)
	{
		operation->width *= -1;
		operation->config |= FLAG_MINUS;
	}
	return (0);
}

int	parse_flags(t_print_op *operation)
{
	const char	*format;

	format = operation->format;
	while (ft_strchr("-+ #0", *format))
	{
		if (*format == '+')
			operation->config |= FLAG_PLUS;
		if (*format == '-')
			operation->config |= FLAG_MINUS;
		if (*format == ' ')
			operation->config |= FLAG_SPACE;
		if (*format == '#')
			operation->config |= FLAG_HASHTAG;
		if (*format == '0')
			operation->config |= FLAG_ZERO;
		format++;
	}
	operation->format = format;
	return (0);
}
