/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:13:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_e_helper(t_print_op *op)
{
	char	*temp_value;
	char	*temp_zero;

	temp_value = op->v_value;
	while (temp_value && *temp_value && *temp_value != '.')
		temp_zero = ++temp_value;
	while (temp_value && *temp_value)
	{
		if (*temp_value == '0' && !temp_zero)
			temp_zero = temp_value;
		if (!ft_strchr(".0", *temp_value))
			temp_zero = NULL;
		temp_value++;
	}
	if (temp_zero)
		*temp_zero = '\0';
}

void	ft_spec_e(t_print_op *op)
{
	long double	n;
	int			p;

	if (op->length == plength_L)
		n = va_arg(*op->arguments, long double);
	else
		n = va_arg(*op->arguments, double);
	p = 6;
	if (op->config & HAS_PRECISION)
		p = op->precision;
	if (ft_hexfloat_signal(n))
	{
		op->v_signal = ft_strdup("-");
		n *= -1;
	}
	op->v_value = ft_stdfloat_limits(n);
	if (!op->v_value)
	{
		op->v_value = ft_stdfloat_num(n, p);
		op->v_suffix = ft_strdup("e");
		op->v_exponent = ft_nitoa(2, ft_stdfloat_exp(n));
		ft_spec_e_helper(op);
	}
}
