/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:16:53 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 19:13:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_str_precision_interfer(t_ft_printf_flags *flags, char *str)
{
	int		required;
	int		len;

	len = (int)ft_strlen(str);
	if (flags->precision_value >= len || (flags->precision_value == 0 &&
		!flags->precision_enabled))
		required = flags->width_value - len;
	else if (flags->precision_value == 0 && flags->width_enabled)
		required = flags->width_value;
	else if (flags->precision_negative)
		required = flags->width_value - len;
	else
		required = flags->width_value - flags->precision_value;
	return (required);
}

void		ft_printf_format_str(t_ft_printf_group *group)
{
	char			*str;
	int				required;

	str = va_arg(group->params->arguments, char*);
	if (str == NULL)
		str = "(null)";
	required = ft_str_precision_interfer(group->flags, str);
	if (group->flags->side)
	{
		ft_printf_putstr(group, str);
		ft_printf_width_handler(required, group);
	}
	else
	{
		ft_printf_width_handler(required, group);
		ft_printf_putstr(group, str);
	}
}
