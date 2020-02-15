/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:59:31 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/12 22:05:44 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_precision_zeros(t_ft_printf_group *group, char *str)
{
	int	zeros_needed;

	zeros_needed = group->flags->precision_value - (int)ft_strlen(str);
	if (group->flags->precision_negative)
		return ;
	while (zeros_needed && zeros_needed > 0)
	{
		ft_printf_putchar(group->params, '0');
		zeros_needed--;
	}
}

void		ft_printf_putdecimal(t_ft_printf_group *group, char *str)
{
	int	i;

	i = 0;
	if (group->flags->precision_value >= (int)ft_strlen(str) ||
		(group->flags->precision_enabled && group->flags->precision_value == 0))
	{
		ft_add_precision_zeros(group, str);
		if (str[i] == '0' && group->flags->precision_value == 0)
			return ;
		while (str[i])
		{
			ft_printf_putchar(group->params, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_printf_putchar(group->params, str[i]);
			i++;
		}
	}
}

void		ft_printf_putpointer(t_ft_printf_group *group, char *str)
{
	int	i;

	i = 0;
	if (group->flags->precision_value >= (int)ft_strlen(str))
	{
		ft_add_precision_zeros(group, str);
		while (str[i])
		{
			ft_printf_putchar(group->params, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_printf_putchar(group->params, str[i]);
			i++;
		}
	}
}

void		ft_printf_put_uint(t_ft_printf_group *group, char *str)
{
	int	i;

	i = 0;
	if (group->flags->precision_value >= (int)ft_strlen(str) ||
		(group->flags->precision_enabled && group->flags->precision_value == 0))
	{
		ft_add_precision_zeros(group, str);
		if (str[i] == '0' && group->flags->precision_value == 0)
			return ;
		while (str[i])
		{
			ft_printf_putchar(group->params, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_printf_putchar(group->params, str[i]);
			i++;
		}
	}
}
