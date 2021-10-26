/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:04:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_n(t_print_op *op)
{
	void	*ptr;

	ptr = va_arg(*op->arguments, void *);
	if (ptr)
	{
		if (op->length == plength_none)
			*((int *)ptr) = (int)op->print_size;
		else if (op->length == plength_hh)
			*((signed char *)ptr) = (signed char)op->print_size;
		else if (op->length == plength_h)
			*((short int *)ptr) = (short int)op->print_size;
		else if (op->length == plength_l)
			*((long int *)ptr) = 4;
		else if (op->length == plength_ll)
			*((long long int *)ptr) = (long long int)op->print_size;
		else
			*((size_t *)ptr) = (size_t)op->print_size;
	}
}
