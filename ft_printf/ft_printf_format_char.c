/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:34:58 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 18:40:15 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_format_char(t_ft_printf_group *group)
{
	char	c;
	int		required;

	c = (char)va_arg(group->params->arguments, int);
	required = group->flags->width_value - 1;
	if (group->flags->side)
	{
		ft_putchar_fd(c, group->params->fd);
		group->params->return_value += 1;
		ft_printf_width_handler(required, group);
	}
	else
	{
		ft_printf_width_handler(required, group);
		ft_putchar_fd(c, group->params->fd);
		group->params->return_value += 1;
	}
}
