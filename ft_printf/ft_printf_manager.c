/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:44:48 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/10 21:23:25 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_manager(t_ft_printf_params *params)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	while ((c = params->format[i]))
	{
		i++;
		if (c != '%')
			ft_printf_putchar(params, (char)c);
		else
			ft_printf_format_handle(params, &i);
	}
}
