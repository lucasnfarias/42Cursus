/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:45:33 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 14:59:52 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(t_ft_printf_group *group, char *str)
{
	int	i;

	i = 0;
	if (group->flags->precision_enabled && !group->flags->precision_negative)
	{
		while (str[i] && i < group->flags->precision_value)
		{
			ft_putchar_fd(str[i], group->params->fd);
			group->params->return_value += 1;
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar_fd(str[i], group->params->fd);
			group->params->return_value += 1;
			i++;
		}
	}
}
