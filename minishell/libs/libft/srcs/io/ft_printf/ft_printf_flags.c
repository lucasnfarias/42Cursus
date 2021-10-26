/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:45:53 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/29 10:23:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flags_plus_space(t_print_op *op)
{
	if (!ft_strchr("cspn%%", op->specifier) && op->valid)
	{
		if (!op->v_signal)
		{
			if (op->config & FLAG_PLUS)
				op->v_signal = ft_strdup("+");
			else
				op->v_signal = ft_strdup(" ");
		}
	}
}

void	ft_printf_flags_hashtag_base(t_print_op *op)
{
	if (ft_strchr("oxX", op->specifier) && *op->v_value != '0')
	{
		if (op->specifier == 'o')
			op->v_prefix = ft_strdup("0");
		if (op->specifier == 'x' || op->specifier == 'X')
			op->v_prefix = ft_strdup("0x");
	}
}

void	ft_printf_flags_hashtag_dot(t_print_op *op)
{
	char	*temp;

	if (ft_strchr("aAeEgGfF", op->specifier) && !ft_strchr(op->v_value, '.'))
	{
		temp = ft_strjoin(op->v_value, ".");
		free(op->v_value);
		op->v_value = temp;
	}
}

void	ft_printf_flags(t_print_op *op)
{
	if (op->config & FLAG_PLUS || op->config & FLAG_SPACE)
		ft_printf_flags_plus_space(op);
	if (op->config & FLAG_HASHTAG)
	{
		ft_printf_flags_hashtag_base(op);
		ft_printf_flags_hashtag_dot(op);
	}
}
