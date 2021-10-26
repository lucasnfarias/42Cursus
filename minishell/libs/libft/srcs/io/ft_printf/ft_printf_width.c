/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:43:37 by msales-a          #+#    #+#             */
/*   Updated: 2020/11/03 21:01:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width(t_print_op *op)
{
	int	length;

	if (op->config & HAS_WIDTH)
	{
		length = op->width;
		length -= ft_strlen(op->v_signal);
		length -= ft_strlen(op->v_prefix);
		length -= ft_strlen(op->v_precision);
		length -= ft_strlen(op->v_value);
		length -= ft_strlen(op->v_suffix);
		length -= ft_strlen(op->v_exponent);
		if (op->config & FLAG_MINUS)
			op->v_width_s = ft_repeatchr(' ', length);
		else if (op->v_precision)
			op->v_width_p = ft_repeatchr(' ', length);
		else if (op->config & FLAG_ZERO && *op->v_value != '\0')
			op->v_width_i = ft_repeatchr('0', length);
		else
			op->v_width_p = ft_repeatchr(' ', length);
	}
}
