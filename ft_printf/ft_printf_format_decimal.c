/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:28:50 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 22:17:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_neg(long n)
{
	if (n < 0)
		return (-1);
	return (0);
}

static int	ft_int_precision_interfer(t_ft_printf_flags *flags, char *str)
{
	int		required;
	int		len;

	len = (int)ft_strlen(str);
	required = 0;
	if (str[0] == '0' && flags->precision_value == 0 &&
		flags->precision_enabled)
		required = flags->width_value;
	else if (flags->width_enabled && flags->precision_negative)
		required = flags->width_value - len;
	else if (flags->precision_enabled && flags->precision_value == 0)
		required = flags->width_value - len;
	else if (flags->precision_value <= len && !flags->width_enabled)
		required = flags->width_value - len;
	else if (flags->precision_value > len && flags->width_enabled)
		required = flags->width_value - flags->precision_value;
	else if (flags->precision_value <= len && flags->width_enabled)
		required = flags->width_value - len;
	return (required);
}

static void	ft_check_width_enabled(t_ft_printf_group *group, int neg, int req)
{
	if ((!group->flags->width_enabled || req <= 0) && neg == -1)
		ft_printf_putchar(group->params, '-');
	else if (group->flags->side && neg == -1 && req <= 0)
		ft_printf_putchar(group->params, '-');
	else if (group->flags->side && neg == -1)
		ft_printf_putchar(group->params, '-');
}

void		ft_printf_format_decimal(t_ft_printf_group *group)
{
	int				num;
	char			*str;
	int				required;

	num = va_arg(group->params->arguments, int);
	required = ft_is_neg(num);
	str = ft_itoa_base(ft_abs(num), "0123456789");
	required += ft_int_precision_interfer(group->flags, str);
	if (group->flags->side || group->flags->width_negative)
	{
		ft_check_width_enabled(group, ft_is_neg(num), required);
		ft_printf_putdecimal(group, str);
		ft_printf_width_handler_num(required, group, ft_is_neg(num));
	}
	else
	{
		ft_printf_width_handler_num(required, group, ft_is_neg(num));
		ft_check_width_enabled(group, ft_is_neg(num), required);
		ft_printf_putdecimal(group, str);
	}
	free(str);
}
