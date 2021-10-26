/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:22:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:01:31 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(t_print_op *op, char *printable)
{
	char	*value;

	value = printable;
	if (value)
	{
		while (*value)
		{
			if (op->null_present && *value == '_')
				*value = '\0';
			if (op->valid && op->upper)
				*value = ft_toupper(*value);
			ft_putchar_fd(*(value++), 1);
			op->print_size++;
		}
		free(printable);
	}
}

void	ft_printf_print_all(t_print_op *op)
{
	ft_printf_putstr(op, op->v_width_p);
	ft_printf_putstr(op, op->v_signal);
	ft_printf_putstr(op, op->v_prefix);
	ft_printf_putstr(op, op->v_width_i);
	ft_printf_putstr(op, op->v_precision);
	ft_printf_putstr(op, op->v_value);
	ft_printf_putstr(op, op->v_suffix);
	ft_printf_putstr(op, op->v_exponent);
	ft_printf_putstr(op, op->v_width_s);
}

int	ft_xprintf(t_print_op *op)
{
	ft_printf_parser(op);
	ft_printf_specifier(op);
	ft_printf_flags(op);
	ft_printf_precision(op);
	ft_printf_width(op);
	if (op->specifier != 'n')
		ft_printf_print_all(op);
	return (1);
}

int	ft_vprintf(const char *format, va_list *arguments)
{
	t_print_op	op;

	if (!format || !arguments)
		return (0);
	op.format = format;
	op.arguments = arguments;
	op.print_size = 0;
	while (*op.format)
	{
		if (*op.format == '%')
		{
			ft_xprintf(&op);
			continue ;
		}
		ft_putchar_fd(*op.format, 1);
		op.format++;
		op.print_size++;
	}
	return (op.print_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		index;

	if (!format)
		return (0);
	va_start(arguments, format);
	index = ft_vprintf(format, &arguments);
	va_end(arguments);
	return (index);
}
