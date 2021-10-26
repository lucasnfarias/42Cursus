/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/28 15:32:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_x(t_print_op *op)
{
	char			*base;
	unsigned long	value;

	base = "0123456789abcdef";
	if (op->length <= plength_h)
		value = va_arg(*op->arguments, unsigned int);
	else if (op->length <= plength_l)
		value = va_arg(*op->arguments, unsigned long);
	else
		value = va_arg(*op->arguments, size_t);
	op->v_value = ft_ullitoabase(value, base);
}
