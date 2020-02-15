/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_percentage.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:25:27 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/11 17:10:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_format_percentage(t_ft_printf_group *group)
{
	char	c;
	int		required;

	c = '%';
	required = group->flags->width_value - 1;
	if (group->flags->side)
	{
		ft_putchar_fd(c, group->params->fd);
		ft_printf_width_handler(required, group);
	}
	else
	{
		ft_printf_width_handler(required, group);
		ft_putchar_fd(c, group->params->fd);
	}
	group->params->return_value += 1;
}
