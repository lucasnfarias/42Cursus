/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:33:38 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 22:15:29 by lniehues         ###   ########.fr       */
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

static void	ft_printf_putzerox(t_ft_printf_group *group, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], group->params->fd);
		group->params->return_value += 1;
		i++;
	}
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

void		ft_printf_format_pointer(t_ft_printf_group *group)
{
	unsigned long	ptr;
	char			*str;
	int				required;

	ptr = (unsigned long)va_arg(group->params->arguments, void *);
	str = ft_itoa_unsigned_base(ptr, "0123456789abcdef");
	str = ft_pf_check_empty(str, ptr, group);
	required = ft_int_precision_interfer(group->flags, str) - 2;
	if (group->flags->side)
	{
		ft_printf_putzerox(group, "0x");
		ft_printf_putpointer(group, str);
		ft_printf_width_handler_num(required, group, 0);
	}
	else
	{
		ft_printf_width_handler_num(required, group, 0);
		ft_printf_putzerox(group, "0x");
		ft_printf_putpointer(group, str);
	}
	free(str);
}
