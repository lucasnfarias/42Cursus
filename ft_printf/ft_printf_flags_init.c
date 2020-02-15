/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:52:56 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/10 16:15:25 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flags_init(t_ft_printf_flags *flags)
{
	flags->letter_format = '\0';
	flags->hex_lower = 0;
	flags->side = 0;
	flags->minus_sign = 0;
	flags->width_value = 0;
	flags->width_enabled = 0;
	flags->width_negative = 0;
	flags->precision_value = 0;
	flags->precision_enabled = 0;
	flags->precision_negative = 0;
	flags->padding_char = ' ';
}
