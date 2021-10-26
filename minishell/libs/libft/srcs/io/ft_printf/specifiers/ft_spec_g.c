/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:12:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_g_f(t_print_op *op, long double value, int precision)
{
	op->v_signal = NULL;
	if (ft_hexfloat_signal(value))
		op->v_signal = ft_strdup("-");
	if (ft_hexfloat_signal(value))
		value *= -1;
	op->v_value = ft_ftoa(value, precision);
	ft_spec_e_helper(op);
}

void	ft_spec_g_e(t_print_op *op, long double value, int precision)
{
	op->v_signal = NULL;
	if (ft_hexfloat_signal(value))
		op->v_signal = ft_strdup("-");
	if (ft_hexfloat_signal(value))
		value *= -1;
	op->v_value = ft_stdfloat_num(value, precision);
	op->v_suffix = ft_strdup("e");
	op->v_exponent = ft_nitoa(2, ft_stdfloat_exp(value));
	ft_spec_e_helper(op);
}

void	ft_spec_g(t_print_op *op)
{
	long double	value;
	int			x;
	int			p;

	if (op->length == plength_L)
		value = va_arg(*op->arguments, long double);
	else
		value = va_arg(*op->arguments, double);
	if (!(op->config & HAS_PRECISION))
		p = 6;
	else if (op->config & HAS_PRECISION && op->precision == 0)
		p = 1;
	else
		p = op->precision;
	x = ft_stdfloat_exp(value);
	if (p > x && x >= -4)
		ft_spec_g_f(op, value, p - (x + 1));
	else
		ft_spec_g_e(op, value, p - 1);
}
