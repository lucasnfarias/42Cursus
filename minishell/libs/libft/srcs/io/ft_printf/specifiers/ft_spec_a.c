/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:06:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_a(t_print_op *op)
{
	double	value;
	int		p;
	int		exp;

	value = va_arg(*op->arguments, double);
	op->v_value = ft_stdfloat_limits(value);
	if (!op->v_value)
	{
		if (op->config & HAS_PRECISION)
			p = op->precision;
		else
			p = ft_hexfloat_precision(value);
		op->v_signal = NULL;
		if (ft_hexfloat_signal(value))
			op->v_signal = ft_strdup("-");
		op->v_prefix = ft_strdup("0x");
		op->v_value = ft_hexfloat_mantissa(value, p);
		exp = ft_hexfloat_exp(value);
		if (exp < 0)
			op->v_suffix = ft_strdup("p-");
		else
			op->v_suffix = ft_strdup("p+");
		op->v_exponent = ft_itoa(exp);
	}
}
