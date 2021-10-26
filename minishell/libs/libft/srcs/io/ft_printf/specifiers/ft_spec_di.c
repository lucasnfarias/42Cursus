/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/08/17 18:09:20 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_di(t_print_op *op)
{
	long long int	value;

	value = 0;
	if (op->length <= plength_h)
		value = va_arg(*op->arguments, int);
	else if (op->length <= plength_l)
		value = va_arg(*op->arguments, long int);
	else if (op->length <= plength_ll)
		value = va_arg(*op->arguments, long long int);
	else
		value = va_arg(*op->arguments, size_t);
	if (value < 0)
	{
		op->v_signal = ft_strdup("-");
		value *= -1;
	}
	op->v_value = ft_ullitoa(value);
}
