/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_uint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:15:11 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 22:14:03 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_neg(long n)
{
	if (n < 0)
		return (-1);
	return (0);
}

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

void		ft_printf_format_uint(t_ft_printf_group *group)
{
	unsigned int	num;
	char			*str;
	int				required;

	num = va_arg(group->params->arguments, unsigned int);
	str = ft_itoa_unsigned_base(num, "0123456789");
	str = ft_pf_check_empty(str, num, group);
	required = ft_int_precision_interfer(group->flags, str);
	if (group->flags->side)
	{
		ft_printf_put_uint(group, str);
		ft_printf_width_handler_num(required, group, ft_is_neg(num));
	}
	else
	{
		ft_printf_width_handler_num(required, group, ft_is_neg(num));
		ft_printf_put_uint(group, str);
	}
	free(str);
}
