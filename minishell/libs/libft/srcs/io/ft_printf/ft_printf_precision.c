/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:43:37 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/29 08:29:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision_diuox(t_print_op *op)
{
	int		length;

	if (op->precision == 0 && *op->v_value == '0')
		*op->v_value = '\0';
	else
	{
		length = op->precision - ft_strlen(op->v_value);
		op->v_precision = ft_repeatchr('0', length);
	}
}

void	ft_printf_precision_s(t_print_op *op)
{
	char	*temp;

	if ((size_t)op->precision < ft_strlen(op->v_value))
	{
		temp = ft_substr(op->v_value, 0, op->precision);
		free(op->v_value);
		op->v_value = temp;
	}
}

void	ft_printf_precision(t_print_op *op)
{
	if (op->config & HAS_PRECISION)
	{
		if (ft_strchr("diuoxX", op->specifier))
			ft_printf_precision_diuox(op);
		else if (op->specifier == 's')
			ft_printf_precision_s(op);
	}
}
