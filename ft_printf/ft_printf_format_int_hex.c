/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_int_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:01:57 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 22:17:02 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_pf_check_empty(char *str, unsigned long ptr,
			t_ft_printf_group *group)
{
	if (ptr == 0 && group->flags->precision_enabled &&
			group->flags->precision_value == 0)
	{
		free(str);
		return (ft_empty_str());
	}
	return (str);
}

static int	ft_int_precision_interfer(t_ft_printf_flags *flags, char *str)
{
	int		required;
	int		len;

	len = (int)ft_strlen(str);
	required = 0;
	if (flags->precision_enabled && flags->precision_value == 0)
		required = flags->width_value - len;
	else if (flags->precision_value <= len && !flags->width_enabled)
		required = flags->width_value - len;
	else if (flags->precision_value > len && flags->width_enabled)
		required = flags->width_value - flags->precision_value;
	else if (flags->precision_value <= len && flags->width_enabled)
		required = flags->width_value - len;
	return (required);
}

void		ft_printf_format_int_hex(t_ft_printf_group *group)
{
	unsigned int	num;
	char			*str;
	int				required;

	num = va_arg(group->params->arguments, unsigned int);
	if ((group->flags->hex_lower = group->flags->letter_format == 'x'))
		str = ft_itoa_unsigned_base(num, "0123456789abcdef");
	else
		str = ft_itoa_unsigned_base(num, "0123456789ABCDEF");
	str = ft_pf_check_empty(str, num, group);
	required = ft_int_precision_interfer(group->flags, str);
	if (group->flags->side)
	{
		ft_printf_putdecimal(group, str);
		ft_printf_width_handler_num(required, group, 0);
	}
	else
	{
		ft_printf_width_handler_num(required, group, 0);
		ft_printf_putdecimal(group, str);
	}
	free(str);
}
