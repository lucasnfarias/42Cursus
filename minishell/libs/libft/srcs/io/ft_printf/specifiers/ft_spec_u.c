/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/28 15:31:58 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_u(t_print_op *op)
{
	unsigned long long int	value;

	if (op->length <= plength_h)
		value = va_arg(*op->arguments, unsigned int);
	else if (op->length <= plength_l)
		value = va_arg(*op->arguments, unsigned long int);
	else if (op->length <= plength_ll)
		value = va_arg(*op->arguments, unsigned long long int);
	else
		value = va_arg(*op->arguments, size_t);
	op->v_value = ft_ullitoa(value);
}
