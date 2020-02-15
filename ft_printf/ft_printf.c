/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:53:05 by lniehues          #+#    #+#             */
/*   Updated: 2020/02/07 14:32:32 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_ft_printf_params	params;

	params.format = format;
	params.fd = 1;
	params.return_value = 0;
	va_start(params.arguments, format);
	ft_printf_manager(&params);
	va_end(params.arguments);
	return (params.return_value);
}
