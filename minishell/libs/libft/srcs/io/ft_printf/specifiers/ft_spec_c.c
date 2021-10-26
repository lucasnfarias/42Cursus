/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/28 13:12:32 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_c(t_print_op *op)
{
	int	value;

	value = va_arg(*op->arguments, int);
	if (value == 0)
	{
		op->v_value = ft_strdup("_");
		op->null_present = true;
	}
	else
		op->v_value = ft_repeatchr(value, 1);
}
