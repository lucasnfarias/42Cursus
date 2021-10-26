/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:14:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:02:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_parser_cleaner(t_print_op *operation)
{
	operation->config = 0;
	operation->width = 0;
	operation->precision = 0;
	operation->specifier = 0;
	operation->null_present = false;
	operation->valid = false;
	operation->v_signal = NULL;
	operation->v_prefix = NULL;
	operation->v_width_p = NULL;
	operation->v_width_i = NULL;
	operation->v_width_s = NULL;
	operation->v_precision = NULL;
	operation->v_value = NULL;
	operation->v_suffix = NULL;
	operation->v_exponent = NULL;
	operation->upper = false;
}

int	ft_printf_parser(t_print_op *operation)
{
	if (*operation->format == '%')
		operation->format++;
	ft_printf_parser_cleaner(operation);
	parse_flags(operation);
	parse_width(operation);
	parse_precision(operation);
	parse_length(operation);
	if (parse_specifier(operation))
		return (0);
	operation->valid = true;
	return (1);
}
